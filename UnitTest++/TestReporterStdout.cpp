#include "TestReporterStdout.h"
#include <cstdio>

// cstdio doesn't pull in namespace std on VC6, so we do it here.
#if defined(UNITTEST_WIN32) && (_MSC_VER == 1200)
	namespace std {}
#endif

namespace UnitTest {

TestReporterStdout::TestReporterStdout()
	: m_FileHandle(stdout)
	, m_ErrorFileHandle(stderr)
{
}

TestReporterStdout::TestReporterStdout(FILE* fileHandle)
	: m_FileHandle(fileHandle)
	, m_ErrorFileHandle(fileHandle)
{
}

TestReporterStdout::TestReporterStdout(FILE* fileHandle, FILE* errorFileHandle)
	: m_FileHandle(fileHandle)
	, m_ErrorFileHandle(errorFileHandle)
{
}

void TestReporterStdout::Output(bool failure, const char* log, va_list list)
{
	FILE* const handle = failure ? m_ErrorFileHandle : m_FileHandle;
	vfprintf(handle, log, list);
}

}
