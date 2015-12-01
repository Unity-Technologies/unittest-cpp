#ifndef UNITTEST_DEFERREDTESTREPORTER_H
#define UNITTEST_DEFERREDTESTREPORTER_H

#include "Config.h"

#ifndef UNITTEST_NO_DEFERRED_REPORTER

#include "TestReporter.h"
#include "DeferredTestResult.h"

#include <list>

UNITTEST_STDVECTOR_LINKAGE(UnitTest::DeferredTestResult);

namespace UnitTest
{

class UNITTEST_LINKAGE DeferredTestReporter : public TestReporter
{
public:
	DeferredTestReporter();
	virtual ~DeferredTestReporter();

    virtual void ReportTestStart(TestDetails const& details);
    virtual void ReportFailure(TestDetails const& details, char const* failure);
    virtual void ReportTestFinish(TestDetails const& details, float secondsElapsed);
	virtual void ReportTestProperty(TestDetails const& test, const char* propName, const UnitTest::TestProperty& propValue);

    typedef std::list< DeferredTestResult > DeferredTestResultList;
    DeferredTestResultList& GetResults();

private:
	DeferredTestReporter(const DeferredTestReporter&);
	DeferredTestReporter& operator =(const DeferredTestReporter&);

    DeferredTestResultList m_results;
};

}

#endif
#endif
