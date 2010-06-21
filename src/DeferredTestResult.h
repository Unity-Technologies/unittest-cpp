#ifndef UNITTEST_DEFERREDTESTRESULT_H
#define UNITTEST_DEFERREDTESTRESULT_H

#include <string>
#include <list>

namespace UnitTest
{

class DeferredTestResult
{
public:
	DeferredTestResult();
    DeferredTestResult(char const* suite, char const* test);

	~DeferredTestResult();
	DeferredTestResult(const DeferredTestResult& that);
	DeferredTestResult& operator =(const DeferredTestResult& that);

    std::string suiteName;
    std::string testName;
    std::string failureFile;
    
    typedef std::pair< int, std::string > Failure;
    typedef std::list< Failure > FailureVec;
    FailureVec failures;
    
    float timeElapsed;
	bool failed;
};

}

#endif //UNITTEST_DEFERREDTESTRESULT_H
