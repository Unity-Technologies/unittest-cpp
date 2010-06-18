#ifndef UNITTEST_NUNITTESTREPORTER_H
#define UNITTEST_NUNITTESTREPORTER_H

#include "DeferredSuiteReporter.h"

#include <iosfwd>

namespace UnitTest
{

class NunitTestReporter : public DeferredSuiteReporter
{
public:
    explicit NunitTestReporter(std::ostream& ostream);
	virtual ~NunitTestReporter();

protected:
	virtual	void ReportBeginResults(int totalTestCount, int failedTestCount, int failureCount, float secondsElapsed);
	virtual void ReportSuite(DeferredSuiteResult const& result);
	virtual	void ReportEndResults();

private:
    NunitTestReporter(NunitTestReporter const&);
    NunitTestReporter& operator=(NunitTestReporter const&);

    void AddXmlElement(char const* encoding);
    void BeginResults(int totalTestCount, int failedTestCount, int failureCount, float secondsElapsed);
    void EndResults();
	void BeginSuite(char const* suiteName, bool failed, float timeElapsed);
	void EndSuite(char const* suiteName);

    void BeginTest(DeferredTestResult const& result);
    void AddFailure(DeferredTestResult const& result);
    void EndTest(DeferredTestResult const& result);

    std::ostream& m_ostream;
};

}

#endif
