#ifndef UNITTEST_ASSERTEXCEPTION_H
#define UNITTEST_ASSERTEXCEPTION_H

#include <exception>


namespace UnitTest {

class AssertException : public std::exception
{
public:
    AssertException(char const* description, char const* filename, int lineNumber);
    virtual ~AssertException() throw();

    virtual char const* what() const throw();

    char const* Filename() const;
    int LineNumber() const;
	
private:
	enum 
	{ 
		kDescriptionLength = 512,
		kFileNameLength = 256,
	};
    char m_description[kDescriptionLength];
    char m_filename[kFileNameLength];
    int m_lineNumber;
};

}

#endif
