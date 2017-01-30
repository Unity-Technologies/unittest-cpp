#include "TestDetails.h"

namespace UnitTest {

TestDetails::TestDetails(char const* testName_, char const* suiteName_, const char* category, char const* filename_, int lineNumber_)
    : suiteName(suiteName_)
    , testName(testName_)
    , filename(filename_)
	, category(category)
    , lineNumber(lineNumber_)
{
}

TestDetails::TestDetails(const TestDetails& details, int lineNumber_)
    : suiteName(details.suiteName)
    , testName(details.testName)
    , filename(details.filename)
    , lineNumber(lineNumber_)
	, category(details.category)
{
}


}
