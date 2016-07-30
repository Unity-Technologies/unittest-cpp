#ifndef UNITTEST_TESTDETAILS_H
#define UNITTEST_TESTDETAILS_H

#include "TestProperty.h"

namespace UnitTest {

class TestDetails
{
public:
	TestDetails ()
		: suiteName (0)
		, testName (0)
		, filename (0)
		, category (0)
		, lineNumber (-1) {}

    TestDetails(char const* testName, char const* suiteName, const char* category, char const* filename, int lineNumber);
    TestDetails(const TestDetails& details, char const* filename, int lineNumber);

    char const* suiteName;
    char const* testName;
    char const* filename;
	char const* category;
    int lineNumber;
};

}

#endif
