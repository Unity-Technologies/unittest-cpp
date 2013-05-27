#ifndef UNITTEST_TESTDETAILS_H
#define UNITTEST_TESTDETAILS_H

#include "HelperMacros.h"

namespace UnitTest {

class UNITTEST_LINKAGE TestDetails
{
public:
    TestDetails(char const* testName, char const* suiteName, char const* filename, int lineNumber);
    TestDetails(const TestDetails& details, int lineNumber);

    char const* suiteName;
    char const* testName;
    char const* filename;
    int lineNumber;
    mutable bool timeConstraintExempt;
};

}

#endif
