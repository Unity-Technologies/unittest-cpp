#ifndef UNITTEST_TESTREPORTERSTDOUT_H
#define UNITTEST_TESTREPORTERSTDOUT_H

#include "TestReporter.h"

#include <cstdio>

namespace UnitTest {

class TestReporterStdout : public TestReporter
{
public:
	TestReporterStdout(FILE* fileHandle = stdout);

private:
    virtual void ReportTestStart(TestDetails const& test);
    virtual void ReportFailure(TestDetails const& test, char const* failure);
    virtual void ReportTestFinish(TestDetails const& test, float secondsElapsed);
    virtual void ReportSummary(int totalTestCount, int failedTestCount, int failureCount, float secondsElapsed);

	FILE*	m_fileHandle;
};

}

#endif 
