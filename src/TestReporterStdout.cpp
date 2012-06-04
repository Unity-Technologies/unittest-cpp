#include "TestReporterStdout.h"
#include <cstdio>

namespace UnitTest {

TestReporterStdout::TestReporterStdout(FILE* fileHandle)
	: m_fileHandle(fileHandle)
{
}

void TestReporterStdout::Output(const char* log, va_list list)
{
	vfprintf(m_fileHandle, log, list);
}

}
