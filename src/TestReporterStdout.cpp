#include "TestReporterStdout.h"
#include <cstdio>

#include "TestDetails.h"

namespace UnitTest {

TestReporterStdout::TestReporterStdout(FILE* fileHandle)
	: m_fileHandle(fileHandle)
{
}

void TestReporterStdout::ReportFailure(TestDetails const& details, char const* failure)
{
#if defined(__APPLE__) || defined(__GNUG__)
    char const* const errorFormat = "%s:%d: error: Failure in %s: %s\n";
#else
    char const* const errorFormat = "%s(%d): error: Failure in %s: %s\n";
#endif

	using namespace std;
    fprintf(m_fileHandle, errorFormat, details.filename, details.lineNumber, details.testName, failure);
}

void TestReporterStdout::ReportTestStart(TestDetails const& /*test*/)
{
}

void TestReporterStdout::ReportTestFinish(TestDetails const& /*test*/, float)
{
}

void TestReporterStdout::ReportSummary(int const totalTestCount, int const failedTestCount,
                                       int const failureCount, float secondsElapsed)
{
	using namespace std;

    if (failureCount > 0)
        fprintf(m_fileHandle, "FAILURE: %d out of %d tests failed (%d failures).\n", failedTestCount, totalTestCount, failureCount);
    else
        fprintf(m_fileHandle, "Success: %d tests passed.\n", totalTestCount);

    fprintf(m_fileHandle, "Test time: %.2f seconds.\n", secondsElapsed);
}

}
