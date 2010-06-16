#ifndef UNITTEST_DEFERREDTESTREPORTER_H
#define UNITTEST_DEFERREDTESTREPORTER_H

#include "TestReporter.h"
#include "DeferredTestResult.h"

#include <list>

namespace UnitTest
{

class DeferredTestReporter : public TestReporter
{
public:
	DeferredTestReporter();
	virtual ~DeferredTestReporter();

    virtual void ReportTestStart(TestDetails const& details);
    virtual void ReportFailure(TestDetails const& details, char const* failure);
    virtual void ReportTestFinish(TestDetails const& details, float secondsElapsed);

    typedef std::list< DeferredTestResult > DeferredTestResultList;
    DeferredTestResultList& GetResults();

private:
	DeferredTestReporter(const DeferredTestReporter&);
	DeferredTestReporter& operator =(const DeferredTestReporter&);

    DeferredTestResultList m_results;
};

}

#endif
