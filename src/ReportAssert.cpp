#include "AssertException.h"

#ifdef UNITTEST_FORCE_NO_EXCEPTIONS
#include <stdlib.h>
#include <iostream>
#endif

namespace UnitTest {

void ReportAssert(char const* description, char const* filename, int lineNumber)
{
#ifndef UNITTEST_FORCE_NO_EXCEPTIONS
    throw AssertException(description, filename, lineNumber);
#else
    std::cout << description << " at " << filename << ":" << lineNumber << std::endl;
    ::abort();
#endif
}

}
