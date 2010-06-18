#include "DeferredSuiteReporter.h"
#include "TestDetails.h"
#include "Config.h"

#include <iostream>
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;
using std::ostream;

namespace UnitTest {

DeferredSuiteReporter::DeferredSuiteReporter()
{
}

DeferredSuiteReporter::~DeferredSuiteReporter()
{
}

void DeferredSuiteReporter::ReportTestStart(TestDetails const& details)
{
	if (m_results.empty() || m_results.back().suiteName != details.suiteName)
		m_results.push_back(DeferredSuiteResult(details.suiteName));

	m_results.back().results.push_back(DeferredTestResult(details.suiteName, details.testName));
}

void DeferredSuiteReporter::ReportFailure(TestDetails const& details, char const* failure)
{
	DeferredSuiteResult& suite = m_results.back();
	suite.failed = true;

    DeferredTestResult& r = suite.results.back();
    r.failed = true;
    r.failures.push_back(DeferredTestFailure(details.lineNumber, failure));
    r.failureFile = details.filename;

}

void DeferredSuiteReporter::ReportTestFinish(TestDetails const&, float secondsElapsed)
{
	DeferredSuiteResult& suite = m_results.back();
	DeferredTestResult& r = suite.results.back();
    r.timeElapsed = secondsElapsed;
	suite.timeElapsed += secondsElapsed;
}

void DeferredSuiteReporter::ReportSummary(int totalTestCount, int failedTestCount,
                                          int failureCount, float secondsElapsed)
{
    ReportBeginResults(totalTestCount, failedTestCount, failureCount, secondsElapsed);

    for (DeferredSuiteResultList::const_iterator i = m_results.begin(); i != m_results.end(); ++i)
    {
		ReportSuite(*i);
    }

    ReportEndResults();
}


}
