#ifndef UNITTEST_DEFERREDSUITERESULT_H
#define UNITTEST_DEFERREDSUITERESULT_H

#include "DeferredTestResult.h"

#include <string>
#include <list>

namespace UnitTest
{

class DeferredSuiteResult
{
public:
    DeferredSuiteResult();
    DeferredSuiteResult(char const* suite);
	~DeferredSuiteResult();

	DeferredSuiteResult(const DeferredSuiteResult& that);
	DeferredSuiteResult& operator =(const DeferredSuiteResult& that);

    std::string suiteName;
    
    typedef std::list< DeferredTestResult > ResultVec;
    ResultVec results;
    
    float timeElapsed;
	bool failed;

private:
};

}

#endif //UNITTEST_DEFERREDTESTRESULT_H
