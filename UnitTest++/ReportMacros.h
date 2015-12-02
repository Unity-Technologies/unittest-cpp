#pragma once

#include "Config.h"
#include "TestProperty.h"

#ifdef REPORT_TEST_PROPERTY
    #error UnitTest++ redefines REPORT_TEST_PROPERTY
#endif

#define REPORT_TEST_PROPERTY(NAME, VALUE)                                  \
	do { UnitTest::CurrentTest::Results()->OnTestReportPropery(*UnitTest::CurrentTest::Details(), NAME, UnitTest::TestProperty(VALUE)); } while (0)
