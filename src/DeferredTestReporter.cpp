#include "DeferredTestReporter.h"
#include "TestDetails.h"
#include "Config.h"

namespace UnitTest {

	DeferredTestReporter::DeferredTestReporter()
	{
	}

	DeferredTestReporter::~DeferredTestReporter()
	{
	}

	void DeferredTestReporter::ReportTestStart(TestDetails const& details)
	{
		m_results.push_back(DeferredTestResult(details.suiteName, details.testName));
	}

	void DeferredTestReporter::ReportFailure(TestDetails const& details, char const* failure)
	{
		DeferredTestResult& r = m_results.back();
		r.failed = true;
		r.failures.push_back(DeferredTestResult::Failure(details.lineNumber, failure));
		r.failureFile = details.filename;
	}

	void DeferredTestReporter::ReportTestFinish(TestDetails const&, float secondsElapsed)
	{
		DeferredTestResult& r = m_results.back();
		r.timeElapsed = secondsElapsed;
	}
	
	void DeferredTestReporter::ReportTestProperty(TestDetails const& test, const char* propName, const UnitTest::TestProperty& propValue)
	{
		DeferredTestResult& r = m_results.back();
		r.reportedProperties[propName] = propValue;
	}

	DeferredTestReporter::DeferredTestResultList& DeferredTestReporter::GetResults()
	{
		return m_results;
	}

}
