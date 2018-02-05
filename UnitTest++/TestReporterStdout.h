#ifndef UNITTEST_TESTREPORTERSTDOUT_H
#define UNITTEST_TESTREPORTERSTDOUT_H

#include "TestReporterFormat.h"

#include <cstdio>

using std::FILE;

namespace UnitTest {

class UNITTEST_LINKAGE TestReporterStdout : public TestReporterFormat
{
public:
	TestReporterStdout();
	TestReporterStdout(FILE* fileHandle);
	TestReporterStdout(FILE* fileHandle, FILE* errorFileHandle);

private:
	virtual void Output(bool failure, const char* log, va_list list);

	FILE*	m_FileHandle;
	FILE*   m_ErrorFileHandle;
};

}

#endif 
