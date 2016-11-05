#include "Config.h"
#include "Test.h"
#include "TestList.h"
#include "TestResults.h"
#include "TestAttribute.h"
#include "AssertException.h"
#include "MemoryOutStream.h"
#include "ExecuteTest.h"

#ifdef UNITTEST_POSIX
    #include "Posix/SignalTranslator.h"
#endif

namespace UnitTest {

TestList& Test::GetTestList()
{
    static TestList s_list;
    return s_list;
}

Test::Test(char const* testName, char const* suiteName, const char* categoryName, char const* filename, int lineNumber)
    : m_details(testName, suiteName, categoryName, filename, lineNumber)
    , m_nextTest(0)
	, m_isMockTest(false)
	, m_AttributesInited(false)
{
}

const std::vector<const TestAttribute*>& Test::Attributes() const
{
    // Ideally we would just create the attributes in the constructor - but because
    // CreateAttributes is virtual, it's not safe for us to call at that point. So,
    // we create the attributes lazily, the first time they are accessed.
	if (!m_AttributesInited)
	{
		CreateAttributes(m_Attributes);
		m_AttributesInited = true;
	}
		
	return m_Attributes;
}

Test::~Test()
{
    DestroyAttributes(m_Attributes);
}

void Test::Run()
{
	ExecuteTest(*this, m_details, m_isMockTest);
}

void Test::RunImpl() const
{
}

}
