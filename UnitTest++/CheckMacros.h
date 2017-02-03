#ifndef UNITTEST_CHECKMACROS_H 
#define UNITTEST_CHECKMACROS_H

#include "HelperMacros.h"
#include "ExceptionMacros.h"
#include "Checks.h"
#include "AssertException.h"
#include "MemoryOutStream.h"
#include "TestDetails.h"
#include "CurrentTest.h"
#include "ReportAssertImpl.h"

#ifdef CHECK
    #error UnitTest++ redefines CHECK
#endif

#ifdef CHECK_EQUAL
	#error UnitTest++ redefines CHECK_EQUAL
#endif

#ifdef CHECK_NOT_EQUAL
	#error UnitTest++ redefines CHECK_NOT_EQUAL
#endif

#ifdef CHECK_NULL
    #error UnitTest++ redefines CHECK_NULL
#endif

#ifdef CHECK_NOT_NULL
    #error UnitTest++ redefines CHECK_NOT_NULL
#endif

#ifdef CHECK_CLOSE
	#error UnitTest++ redefines CHECK_CLOSE
#endif

#ifdef CHECK_ARRAY_EQUAL
	#error UnitTest++ redefines CHECK_ARRAY_EQUAL
#endif

#ifdef CHECK_ARRAY_CLOSE
	#error UnitTest++ redefines CHECK_ARRAY_CLOSE
#endif

#ifdef CHECK_ARRAY2D_CLOSE
	#error UnitTest++ redefines CHECK_ARRAY2D_CLOSE
#endif

#ifndef DEBUG_BREAK
    #define DEBUG_BREAK while (0)
#endif

#define CHECK(value) \
	UNITTEST_MULTILINE_MACRO_BEGIN \
	UT_TRY \
		({ \
            bool valueToCheck = value; \
            if (!UnitTest::Check(valueToCheck)) \
            { \
                UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), #value); \
                DEBUG_BREAK; \
            } \
		}) \
		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK(" #value ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
		UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				"Unhandled exception in CHECK(" #value ")"); \
            DEBUG_BREAK; \
		}) \
	UNITTEST_MULTILINE_MACRO_END

#define CHECK_MSG(value, message) \
    UNITTEST_MULTILINE_MACRO_BEGIN \
	UT_TRY \
		({ \
            bool valueToCheck = value; \
            if (!UnitTest::Check(valueToCheck)) \
            { \
                UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), message); \
                DEBUG_BREAK; \
            } \
		}) \
		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK_MSG(" #value ", " #message ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
		UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
                    "Unhandled exception in CHECK_MSG(" #value ", " #message ")"); \
            DEBUG_BREAK; \
        }) \
	UNITTEST_MULTILINE_MACRO_END

#define CHECK_EQUAL(expected, actual) \
	UNITTEST_MULTILINE_MACRO_BEGIN \
        UT_TRY \
		({ \
            if (!UnitTest::CheckEqual(*UnitTest::CurrentTest::Results(), expected, actual, UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__))) \
                DEBUG_BREAK; \
        }) \
		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK_EQUAL(" #expected ", " #actual ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
        UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
                    "Unhandled exception in CHECK_EQUAL(" #expected ", " #actual ")"); \
            DEBUG_BREAK; \
        }) \
	UNITTEST_MULTILINE_MACRO_END

#define CHECK_NOT_EQUAL(comperand, actual) \
    UNITTEST_MULTILINE_MACRO_BEGIN \
        UT_TRY \
		({ \
            if (!UnitTest::CheckNotEqual(*UnitTest::CurrentTest::Results(), comperand, actual, UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__))) \
                DEBUG_BREAK; \
        }) \
		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK_NOT_EQUAL(" #comperand ", " #actual ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
        UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
                    "Unhandled exception in CHECK_NOT_EQUAL(" #comperand ", " #actual ")"); \
            DEBUG_BREAK; \
        }) \
    UNITTEST_MULTILINE_MACRO_END

#define CHECK_NULL(value) \
    UNITTEST_MULTILINE_MACRO_BEGIN \
        UT_TRY \
		({ \
            if (!UnitTest::CheckEqual(*UnitTest::CurrentTest::Results(), static_cast<const void*>(NULL), reinterpret_cast<const void*>(value), UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__))) \
                DEBUG_BREAK; \
        }) \
		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK_NULL(" #value ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
        UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
                    "Unhandled exception in CHECK_NULL(" #value ")"); \
            DEBUG_BREAK; \
        }) \
    UNITTEST_MULTILINE_MACRO_END

#define CHECK_NOT_NULL(value) \
    UNITTEST_MULTILINE_MACRO_BEGIN \
        UT_TRY \
		({ \
            if (!UnitTest::CheckNotEqual(*UnitTest::CurrentTest::Results(), static_cast<const void*>(NULL), reinterpret_cast<const void*>(value), UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__))) \
                DEBUG_BREAK; \
        }) \
		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK_NOT_NULL(" #value ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
        UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
                    "Unhandled exception in CHECK_NOT_NULL(" #value ")"); \
            DEBUG_BREAK; \
        }) \
    UNITTEST_MULTILINE_MACRO_END

#define CHECK_CLOSE(expected, actual, tolerance) \
	UNITTEST_MULTILINE_MACRO_BEGIN \
        UT_TRY \
		({ \
            if (!UnitTest::CheckClose(*UnitTest::CurrentTest::Results(), expected, actual, tolerance, UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__))) \
                DEBUG_BREAK; \
        }) \
		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK_CLOSE(" #expected ", " #actual ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
        UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
                    "Unhandled exception in CHECK_CLOSE(" #expected ", " #actual ")"); \
            DEBUG_BREAK; \
        }) \
	UNITTEST_MULTILINE_MACRO_END

#define CHECK_RELATIVE_ERROR_NO_ZERO(expected, actual, relativeTolerance) \
	UNITTEST_MULTILINE_MACRO_BEGIN \
        UT_TRY \
		({ \
            if (!UnitTest::CheckCloseRelativeNoZero(*UnitTest::CurrentTest::Results(), expected, actual, relativeTolerance, UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__))) \
                DEBUG_BREAK; \
        }) \
		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK_RELATIVE_ERROR_NO_ZERO(" #expected ", " #actual ", " #relativeTolerance ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
        UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
                    "Unhandled exception in CHECK_RELATIVE_ERROR_NO_ZERO(" #expected ", " #actual ", " #relativeTolerance ")"); \
            DEBUG_BREAK; \
        }) \
	UNITTEST_MULTILINE_MACRO_END

#define CHECK_ARRAY_EQUAL(expected, actual, count) \
	UNITTEST_MULTILINE_MACRO_BEGIN \
        UT_TRY \
		({ \
            if (!UnitTest::CheckArrayEqual(*UnitTest::CurrentTest::Results(), expected, actual, count, UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__))) \
                DEBUG_BREAK; \
        }) \
 		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK_ARRAY_EQUAL(" #expected ", " #actual ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
        UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
                    "Unhandled exception in CHECK_ARRAY_EQUAL(" #expected ", " #actual ")"); \
            DEBUG_BREAK; \
        }) \
	UNITTEST_MULTILINE_MACRO_END

#define CHECK_ARRAY_CLOSE(expected, actual, count, tolerance) \
	UNITTEST_MULTILINE_MACRO_BEGIN \
        UT_TRY \
		({ \
            if (!UnitTest::CheckArrayClose(*UnitTest::CurrentTest::Results(), expected, actual, count, tolerance, UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__))) \
                DEBUG_BREAK; \
        }) \
 		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK_ARRAY_CLOSE(" #expected ", " #actual ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
        UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
                    "Unhandled exception in CHECK_ARRAY_CLOSE(" #expected ", " #actual ")"); \
            DEBUG_BREAK; \
        }) \
	UNITTEST_MULTILINE_MACRO_END

#define CHECK_ARRAY2D_CLOSE(expected, actual, rows, columns, tolerance) \
	UNITTEST_MULTILINE_MACRO_BEGIN \
        UT_TRY \
		({ \
            if (!UnitTest::CheckArray2DClose(*UnitTest::CurrentTest::Results(), expected, actual, rows, columns, tolerance, UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__))) \
                DEBUG_BREAK; \
        }) \
 		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK_ARRAY2D_CLOSE(" #expected ", " #actual ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
        UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
                    "Unhandled exception in CHECK_ARRAY2D_CLOSE(" #expected ", " #actual ")"); \
            DEBUG_BREAK; \
        }) \
	UNITTEST_MULTILINE_MACRO_END


// CHECK_THROW and CHECK_ASSERT only exist when UNITTEST_NO_EXCEPTIONS isn't defined (see config.h)
#ifndef UNITTEST_NO_EXCEPTIONS
#define CHECK_THROW(expression, ExpectedExceptionType) \
	UNITTEST_MULTILINE_MACRO_BEGIN \
        bool caught_ = false; \
        try { expression; } \
        catch (ExpectedExceptionType const&) { caught_ = true; } \
		catch (...) {} \
        if (!caught_) \
        { \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), "Expected exception: \"" #ExpectedExceptionType "\" not thrown"); \
            DEBUG_BREAK; \
        } \
	UNITTEST_MULTILINE_MACRO_END


#define CHECK_ASSERT(expression) \
	UNITTEST_MULTILINE_MACRO_BEGIN \
		UnitTest::Detail::ExpectAssert(true); \
		CHECK_THROW(expression, UnitTest::AssertException); \
		UnitTest::Detail::ExpectAssert(false); \
	UNITTEST_MULTILINE_MACRO_END

#endif

#define CHECK_CONTAINS(haystackBegin, haystackEnd, needle) \
    UNITTEST_MULTILINE_MACRO_BEGIN \
        UT_TRY \
		({ \
            if (!UnitTest::CheckContains(*UnitTest::CurrentTest::Results(), haystackBegin, haystackEnd, needle, UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__))) \
                DEBUG_BREAK; \
        }) \
 		UT_CATCH (std::exception, e, \
		{ \
			UnitTest::MemoryOutStream message; \
			message << "Unhandled exception (" << e.what() << ") in CHECK_CONTAINS(" #haystackBegin ", " #haystackEnd ", " #needle ")"; \
			UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
				message.GetText()); \
		}) \
        UT_CATCH_ALL \
		({ \
            UnitTest::CurrentTest::Results()->OnTestFailure(UnitTest::TestDetails(*UnitTest::CurrentTest::Details(), __FILE__, __LINE__), \
                    "Unhandled exception in CHECK_CONTAINS(" #haystackBegin ", " #haystackEnd ", " #needle ")"); \
            DEBUG_BREAK; \
        }) \
    UNITTEST_MULTILINE_MACRO_END

#endif
