#include "Checks.h"
#include <cstring>

namespace UnitTest {

namespace {

bool CheckStringsEqual(TestResults& results, char const* expected, char const* actual,
                       TestDetails const& details)
{
	using namespace std;

    if ((expected && actual) ? strcmp(expected, actual) : (expected || actual))
    {
        UnitTest::MemoryOutStream stream;
        stream << "Expected " << (expected ? expected : "<NULLPTR>") << " but was " << (actual ? actual : "<NULLPTR>");

        results.OnTestFailure(details, stream.GetText());
        return false;
    }
    return true;
}

}


bool CheckEqual(TestResults& results, char const* expected, char const* actual,
                TestDetails const& details)
{
    return CheckStringsEqual(results, expected, actual, details);
}

bool CheckEqual(TestResults& results, char* expected, char* actual,
                TestDetails const& details)
{
    return CheckStringsEqual(results, expected, actual, details);
}

bool CheckEqual(TestResults& results, char* expected, char const* actual,
                TestDetails const& details)
{
    return CheckStringsEqual(results, expected, actual, details);
}

bool CheckEqual(TestResults& results, char const* expected, char* actual,
                TestDetails const& details)
{
    return CheckStringsEqual(results, expected, actual, details);
}


}
