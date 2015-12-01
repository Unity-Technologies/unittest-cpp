#ifndef UNITTEST_TESTREPORTERFORMAT_H
#define UNITTEST_TESTREPORTERFORMAT_H

#include "TestReporter.h"

#include <cstdio>
#include <stdarg.h>

using std::FILE;

namespace UnitTest {

class TestReporterFormat : public TestReporter
{
public:
	TestReporterFormat();

private:
    virtual void ReportTestStart(TestDetails const& test);
    virtual void ReportFailure(TestDetails const& test, char const* failure);
	virtual void ReportTestFinish(TestDetails const& test, float secondsElapsed);
	virtual void ReportTestProperty(TestDetails const& test, const char* propName, const UnitTest::TestProperty& propValue);
	virtual void ReportSummary(int totalTestCount, int failedTestCount, int failureCount, float secondsElapsed);

protected:
	virtual void Output(const char* log, va_list list) = 0;

private:
	void OutputInternal(const char* log, ...);
};

}

#endif 
