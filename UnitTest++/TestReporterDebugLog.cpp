#include "TestReporterDebugLog.h"
#include <cstdio>

extern "C" void printf_console_log(const char* log, va_list list);

namespace UnitTest {

TestReporterDebugLog::TestReporterDebugLog()
{
}

void TestReporterDebugLog::Output(const char* log, va_list list)
{
	printf_console_log(log, list);
}

}
