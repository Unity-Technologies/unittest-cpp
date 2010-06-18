#include "DeferredSuiteResult.h"
#include "Config.h"

namespace UnitTest
{

DeferredSuiteResult::DeferredSuiteResult()
	: suiteName("")
	, results()
	, timeElapsed(0.0f)
	, failed(false)
{
}

DeferredSuiteResult::DeferredSuiteResult(char const* suite)
	: suiteName(suite)
	, results()
	, timeElapsed(0.0f)
	, failed(false)
{
}

DeferredSuiteResult::~DeferredSuiteResult()
{
}

DeferredSuiteResult::DeferredSuiteResult(const DeferredSuiteResult& that)
	: suiteName(that.suiteName)
	, results(that.results)
	, timeElapsed(that.timeElapsed)
	, failed(that.failed)
{
}

DeferredSuiteResult& DeferredSuiteResult::operator =(const DeferredSuiteResult& that)
{
	if(this != &that)
	{
		suiteName = that.suiteName;
		results = that.results;
		timeElapsed = that.timeElapsed;
		failed = that.failed;
	}

	return *this;
}


}
