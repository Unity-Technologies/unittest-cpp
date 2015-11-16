#include "NunitTestReporter.h"
#include "Config.h"

#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;
using std::ostream;
using std::size_t;

namespace {

void ReplaceChar(string& str, char c, string const& replacement)
{
    for (size_t pos = str.find(c); pos != string::npos; pos = str.find(c, pos + 1))
        str.replace(pos, 1, replacement);
}

string XmlEscape(string const& value)
{
    string escaped = value;

    ReplaceChar(escaped, '&', "&amp;");
    ReplaceChar(escaped, '<', "&lt;");
    ReplaceChar(escaped, '>', "&gt;");
    ReplaceChar(escaped, '\'', "&apos;");
    ReplaceChar(escaped, '\"', "&quot;");
 
    return escaped;
}

string BuildFailureMessage(string const& file, int line, string const& message)
{
    ostringstream failureMessage;
    failureMessage << file << "(" << line << ") : " << message;
    return failureMessage.str().c_str();
}

}

namespace UnitTest {

NunitTestReporter::NunitTestReporter(ostream& ostream)
    : m_ostream(ostream)
{
}

NunitTestReporter::~NunitTestReporter()
{
}

void NunitTestReporter::ReportBeginResults(int totalTestCount, int failedTestCount,
                                           int failureCount, float secondsElapsed)
{
    AddXmlElement(NULL);
    BeginResults(totalTestCount, failedTestCount, failureCount, secondsElapsed);
}


void NunitTestReporter::ReportSuite(DeferredSuiteResult const& result)
{
	BeginSuite(result.suiteName.c_str(), result.failed, result.timeElapsed);
	DeferredSuiteResult::ResultVec const& results = result.results;
	for (DeferredSuiteResult::ResultVec::const_iterator i = results.begin(); i != results.end(); ++i)
    {
        BeginTest(*i);

        if (i->failed)
            AddFailure(*i);

        EndTest(*i);
    }
	EndSuite(result.suiteName.c_str());
}

void NunitTestReporter::ReportEndResults()
{
    EndResults();
}


void NunitTestReporter::BeginResults(int totalTestCount, int failedTestCount, 
                                     int failureCount, float secondsElapsed)
{
   m_ostream << "<test-results"
       << " total=\"" << totalTestCount << "\"" 
	   << " errors=\"0\""
       << " failures=\"" << failedTestCount << "\"" 
//       << " failures=\"" << failureCount << "\"" 
       << " time=\"" << secondsElapsed << "\""
       << ">\n";
}

void NunitTestReporter::EndResults()
{
    m_ostream << "</test-results>\n";
}


void NunitTestReporter::BeginSuite(char const* suiteName, bool failed, float timeElapsed)
{
	m_ostream
		<< "\t<test-suite type=\"Namespace\""
		<< " name=\"" << suiteName << "\""
		<< " executed=\"True\""
		<< " result=\"" << (failed ? "Failure" : "Success") << "\""
		<< " success=\"" << (failed ? "False" : "True") << "\""
		<< " time=\"" << timeElapsed << "\""
		<< " asserts=\"0\""
		<< ">" << std::endl
		<< "\t\t<results>" << std::endl;

}

void NunitTestReporter::EndSuite(char const* /*suiteName*/)
{
	m_ostream
		<< "\t\t</results>" << std::endl
		<< "\t</test-suite>" << std::endl;
}

void NunitTestReporter::AddXmlElement(char const* encoding)
{
    m_ostream << "<?xml version=\"1.0\"";

    if (encoding != NULL)
        m_ostream << " encoding=\"" << encoding << "\"";

    m_ostream << "?>\n";
}

void NunitTestReporter::BeginTest(DeferredTestResult const& result)
{
	m_ostream
		<< "\t\t\t<test-case"
        << " name=\"" << result.testName << "\""
		<< " executed=\"True\""
		<< " result=\"" << (result.failed ? "Failure" : "Success") << "\""
		<< " success=\"" << (result.failed ? "False" : "True") << "\""
        << " time=\"" << result.timeElapsed << "\""
		<< " asserts=\"0\""
		<< (result.failed ? ">" : "/>") << std::endl;
}

void NunitTestReporter::EndTest(DeferredTestResult const& result)
{
    if (result.failed)
		m_ostream << "\t\t\t</test-case>" << std::endl;
}

void NunitTestReporter::AddFailure(DeferredTestResult const& result)
{
    for (DeferredTestResult::FailureVec::const_iterator it = result.failures.begin(); 
         it != result.failures.end(); 
         ++it)
    {
        string const escapedMessage = XmlEscape(it->failureStr);
        string const message = BuildFailureMessage(result.failureFile, it->lineNumber, escapedMessage);

        m_ostream
			<< "\t\t\t\t<failure>" << std::endl
			<< "\t\t\t\t\t<message>" << message << "</message>" << std::endl
			<< "\t\t\t\t</failure>" << std::endl;
    }
}

}
