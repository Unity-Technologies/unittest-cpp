#include "AssertException.h"
#include <cstring>

namespace UnitTest {

AssertException::AssertException(char const* description, char const* filename, int lineNumber)
    : m_lineNumber(lineNumber)
{
	using namespace std;

#if defined(_MSC_VER)
    strcpy_s(m_description, kDescriptionLength, description);
    strcpy_s(m_filename, kFileNameLength, filename);
#else
	strncpy(m_description, filename, kDescriptionLength);
    strncpy(m_filename, filename, kFileNameLength);
#endif
}

AssertException::~AssertException() throw()
{
}

char const* AssertException::what() const throw()
{
    return m_description;
}

char const* AssertException::Filename() const
{
    return m_filename;
}

int AssertException::LineNumber() const
{
    return m_lineNumber;
}

}
