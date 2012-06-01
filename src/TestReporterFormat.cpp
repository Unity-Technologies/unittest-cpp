#include "TestReporterFormat.h"
#include <cstdio>

#include "TestDetails.h"

namespace UnitTest {

TestReporterFormat::TestReporterFormat()
{
}

void TestReporterFormat::ReportFailure(TestDetails const& details, char const* failure)
{
#if defined(__APPLE__) || defined(__GNUG__)
    char const* const errorFormat = "%s:%d: error: Failure in %s: %s\n";
#else
    char const* const errorFormat = "%s(%d): error: Failure in %s: %s\n";
#endif

    OutputInternal(errorFormat, details.filename, details.lineNumber, details.testName, failure);
}

void TestReporterFormat::ReportTestStart(TestDetails const& /*test*/)
{
}

void TestReporterFormat::ReportTestFinish(TestDetails const& /*test*/, float)
{
}

void TestReporterFormat::ReportSummary(int const totalTestCount, int const failedTestCount,
                                       int const failureCount, float secondsElapsed)
{
    if (failureCount > 0)
        OutputInternal("FAILURE: %d out of %d tests failed (%d failures).\n", failedTestCount, totalTestCount, failureCount);
    else
        OutputInternal("Success: %d tests passed.\n", totalTestCount);

    OutputInternal("Test time: %.2f seconds.\n", secondsElapsed);
}

void TestReporterFormat::OutputInternal(const char* log, ...)
{
	va_list vl;
	va_start(vl, log);
	Output(log, vl);
	va_end(vl);
}

}
