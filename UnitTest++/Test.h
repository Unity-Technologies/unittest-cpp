#ifndef UNITTEST_TEST_H
#define UNITTEST_TEST_H

#include "TestDetails.h"
#include <vector>

namespace UnitTest {

class TestResults;
class TestList;
struct TestAttribute;

class UNITTEST_LINKAGE Test
{
public:
    explicit Test(char const* testName, char const* suiteName = "DefaultSuite", const char* categoryName = "", char const* filename = "", int lineNumber = 0);
    virtual ~Test();
    void Run();

    TestDetails const m_details;
    Test* m_nextTest;

	mutable bool m_isMockTest;

    static TestList& GetTestList();

    virtual void RunImpl() const;

	const std::vector<const TestAttribute*>& Attributes() const;
	
protected:
	virtual void CreateAttributes(std::vector<const TestAttribute*>& attributes) const { }
    virtual void DestroyAttributes(std::vector<const TestAttribute*>& attributes) const { }

private:
	Test(Test const&);
    Test& operator =(Test const&);

	mutable bool m_AttributesInited;
    mutable std::vector<const TestAttribute*> m_Attributes;
};


}

#endif
