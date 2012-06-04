#include "TestReporterStdout.h"
#include <cstdio>

// cstdio doesn't pull in namespace std on VC6, so we do it here.
#if defined(UNITTEST_WIN32) && (_MSC_VER == 1200)
	namespace std {}
#endif

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
