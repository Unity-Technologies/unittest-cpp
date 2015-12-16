#pragma once

#include "Config.h"
#include "TestProperty.h"

#ifdef REPORT_TEST_PROPERTY
    #error UnitTest++ redefines REPORT_TEST_PROPERTY
#endif

// Add custom property to the current test result.
// The property is a pair of string and UnitTest::TestProperty and will be a test reporter together with other test results.
#define REPORT_TEST_PROPERTY(Name, Value) \
	do { UnitTest::CurrentTest::Results()->OnTestReportPropery(*UnitTest::CurrentTest::Details(), Name, UnitTest::TestProperty(Value)); } while (0)
