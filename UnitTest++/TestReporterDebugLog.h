#ifndef UNITTEST_TESTREPORTERDEBUGLOG_H
#define UNITTEST_TESTREPORTERDEBUGLOG_H

#include "TestReporterFormat.h"

#include <cstdio>

using std::FILE;

namespace UnitTest {

class TestReporterDebugLog : public TestReporterFormat
{
public:
	TestReporterDebugLog();

private:
	virtual void Output(const char* log, va_list list);
};

}

#endif 
