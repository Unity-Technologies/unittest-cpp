#include "DeferredTestResult.h"
#include "Config.h"

namespace UnitTest
{

DeferredTestResult::DeferredTestResult()
	: suiteName("")
	, testName("")
	, failureFile("")
	, timeElapsed(0.0f)
	, failed(false)
{
}

DeferredTestResult::DeferredTestResult(char const* suite, char const* test)
	: suiteName(suite)
	, testName(test)
	, failureFile("")
	, timeElapsed(0.0f)
	, failed(false)
{
}

DeferredTestResult::~DeferredTestResult()
{
}

DeferredTestResult::DeferredTestResult(const DeferredTestResult& that)
	: suiteName(that.suiteName)
	, testName(that.testName)
	, failureFile(that.failureFile)
	, failures(that.failures)
	, timeElapsed(that.timeElapsed)
	, failed(that.failed)
{
}

DeferredTestResult& DeferredTestResult::operator =(const DeferredTestResult& that)
{
	if(this != &that)
	{
		suiteName = that.suiteName;
		testName = that.testName;
		failureFile = that.failureFile;
		failures = that.failures;
		timeElapsed = that.timeElapsed;
		failed = that.failed;
	}

	return *this;
}


}
