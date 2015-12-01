#ifndef UNITTEST_DEFERREDSUITEREPORTER_H
#define UNITTEST_DEFERREDSUITEREPORTER_H

#include "DeferredTestReporter.h"
#include "DeferredSuiteResult.h"

#include <iosfwd>

namespace UnitTest
{

class DeferredSuiteReporter : public TestReporter
{
public:
    DeferredSuiteReporter();
	virtual ~DeferredSuiteReporter();

	virtual void ReportSummary(int totalTestCount, int failedTestCount, int failureCount, float secondsElapsed);
    virtual void ReportTestStart(TestDetails const& details);
    virtual void ReportFailure(TestDetails const& details, char const* failure);
	virtual void ReportTestFinish(TestDetails const& details, float secondsElapsed);
	virtual void ReportTestProperty(TestDetails const& test, const char* propName, const UnitTest::TestProperty& propValue);

    typedef std::list< DeferredSuiteResult > DeferredSuiteResultList;
    DeferredSuiteResultList& GetResults();

protected:
	virtual	void ReportBeginResults(int totalTestCount, int failedTestCount, int failureCount, float secondsElapsed) = 0;
	virtual void ReportSuite(DeferredSuiteResult const& result) = 0;
	virtual	void ReportEndResults() = 0;

private:
    DeferredSuiteReporter(DeferredSuiteReporter const&);
    DeferredSuiteReporter& operator=(DeferredSuiteReporter const&);

	DeferredSuiteResultList	m_results;
};

}

#endif
