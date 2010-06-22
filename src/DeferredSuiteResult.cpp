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
	, timeElapsed(that.timeElapsed)
	, failed(that.failed)
{
	for(ResultVec::const_iterator it = that.results.begin(); it != that.results.end(); ++it)
		results.push_back(*it);
}

DeferredSuiteResult& DeferredSuiteResult::operator =(const DeferredSuiteResult& that)
{
	if(this != &that)
	{
		suiteName = that.suiteName;
		timeElapsed = that.timeElapsed;
		failed = that.failed;

		for(ResultVec::const_iterator it = that.results.begin(); it != that.results.end(); ++it)
			results.push_back(*it);
	}

	return *this;
}


}
