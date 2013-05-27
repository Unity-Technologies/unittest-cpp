#ifndef UNITTEST_TESTDETAILS_H
#define UNITTEST_TESTDETAILS_H

namespace UnitTest {

class TestDetails
{
public:
    TestDetails(char const* testName, char const* suiteName, char const* filename, int lineNumber);
    TestDetails(const TestDetails& details, int lineNumber);

    char const* suiteName;
    char const* testName;
    char const* filename;
    int lineNumber;
};

}

#endif
