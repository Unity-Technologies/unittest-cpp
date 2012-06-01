#ifndef UNITTEST_TESTREPORTERSTDOUT_H
#define UNITTEST_TESTREPORTERSTDOUT_H

#include "TestReporterFormat.h"

#include <cstdio>

using std::FILE;

namespace UnitTest {

class UNITTEST_LINKAGE TestReporterStdout : public TestReporterFormat
{
public:
	TestReporterStdout(FILE* fileHandle = stdout);

private:
	virtual void Output(const char* log, va_list list);

	FILE*	m_fileHandle;
};

}

#endif 
