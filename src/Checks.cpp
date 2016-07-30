#include "Checks.h"
#include <cstring>

namespace UnitTest {

namespace {

bool CheckStringsEqual(TestResults& results, char const* expected, char const* actual,
                       TestDetails const& details)
{
	using namespace std;

    if (expected == actual)
        return true;
    else if (expected == NULL && actual != NULL)
    {
        UnitTest::MemoryOutStream stream;
        stream << "Expected string was null but actual was " << actual;

        results.OnTestFailure(details, stream.GetText());
        return false;

    }
    else if (expected != NULL && actual == NULL)
    {
        UnitTest::MemoryOutStream stream;
        stream << "Expected " << expected << " but was null";

        results.OnTestFailure(details, stream.GetText());
        return false;
    }
    else if (strcmp(expected, actual) != 0) 
    {
        UnitTest::MemoryOutStream stream;
        stream << "Expected " << expected << " but actual was " << actual;

        results.OnTestFailure(details, stream.GetText());
        return false;
    }
    else
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
