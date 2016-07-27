#ifndef UNITTEST_CHECKS_H
#define UNITTEST_CHECKS_H

#include "Config.h"
#include "TestResults.h"
#include "MemoryOutStream.h"

namespace UnitTest {


template< typename Value >
bool Check(Value const value)
{
    return !!value; // doing double negative to avoid silly VS warnings
}


template< typename Expected, typename Actual >
bool CheckEqual(TestResults& results, Expected const& expected, Actual const& actual, TestDetails const& details)
{
    if (!(expected == actual))
    {
        UnitTest::MemoryOutStream stream;
        stream << "Expected " << expected << " but was " << actual;

        results.OnTestFailure(details, stream.GetText());
        return false;
    }
    return true;
}

bool CheckEqual(TestResults& results, char const* expected, char const* actual, TestDetails const& details);

bool CheckEqual(TestResults& results, char* expected, char* actual, TestDetails const& details);

bool CheckEqual(TestResults& results, char* expected, char const* actual, TestDetails const& details);

bool CheckEqual(TestResults& results, char const* expected, char* actual, TestDetails const& details);

inline bool CheckEqual(TestResults& results, const std::string& expected, const std::string& actual, TestDetails const& details)
{
	return CheckEqual(results, expected.c_str(), actual.c_str(), details);
}

template< typename Expected, typename Actual, typename Tolerance >
bool AreClose(Expected const& expected, Actual const& actual, Tolerance const& tolerance)
{
    return (actual >= (expected - tolerance)) && (actual <= (expected + tolerance));
}

template< typename Expected, typename Actual, typename Tolerance >
bool CheckClose(TestResults& results, Expected const& expected, Actual const& actual, Tolerance const& tolerance,
                TestDetails const& details)
{
    if (!AreClose(expected, actual, tolerance))
    { 
        UnitTest::MemoryOutStream stream;
        stream << "Expected " << expected << " +/- " << tolerance << " but was " << actual;

        results.OnTestFailure(details, stream.GetText());
        return false;
    }
    return true;
}

template< typename Expected, typename Actual, typename Tolerance >
bool AreCloseRelative(Expected const& expected, Actual const& actual, Tolerance const& relativeTolerance)
{
	// Relative error
	Expected relativeError = (expected - actual) / expected;
    return ( relativeError <= relativeTolerance );
}

template< typename Expected, typename Actual, typename Tolerance >
bool CheckCloseRelativeNoZero(TestResults& results, Expected const& expected, Actual const& actual,
                Tolerance const& relativeTolerance, TestDetails const& details)
{
    if (!AreCloseRelative(expected, actual, relativeTolerance))
    { 
        UnitTest::MemoryOutStream stream;
        stream << "Expected " << expected << " R(+/-) " << relativeTolerance << " but was " << actual;

        results.OnTestFailure(details, stream.GetText());
        return false;
    }
    return true;
}


template< typename Expected, typename Actual >
bool CheckArrayEqual(TestResults& results, Expected const& expected, Actual const& actual,
                int const count, TestDetails const& details)
{
    bool equal = true;
    for (int i = 0; i < count; ++i)
        equal &= (expected[i] == actual[i]);

    if (!equal)
    {
        UnitTest::MemoryOutStream stream;

		stream << "Expected [ ";

		for (int expectedIndex = 0; expectedIndex < count; ++expectedIndex)
            stream << expected[expectedIndex] << " ";

		stream << "] but was [ ";

		for (int actualIndex = 0; actualIndex < count; ++actualIndex)
            stream << actual[actualIndex] << " ";

		stream << "]";

        results.OnTestFailure(details, stream.GetText());
        return false;
    }

    return true;
}

template< typename Expected, typename Actual, typename Tolerance >
bool ArrayAreClose(Expected const& expected, Actual const& actual, int const count, Tolerance const& tolerance)
{
    bool equal = true;
    for (int i = 0; i < count; ++i)
        equal &= AreClose(expected[i], actual[i], tolerance);
    return equal;
}

template< typename Expected, typename Actual, typename Tolerance >
bool CheckArrayClose(TestResults& results, Expected const& expected, Actual const& actual,
                   int const count, Tolerance const& tolerance, TestDetails const& details)
{
    bool equal = ArrayAreClose(expected, actual, count, tolerance);

    if (!equal)
    {
        UnitTest::MemoryOutStream stream;

        stream << "Expected [ ";
        for (int expectedIndex = 0; expectedIndex < count; ++expectedIndex)
            stream << expected[expectedIndex] << " ";
        stream << "] +/- " << tolerance << " but was [ ";

		for (int actualIndex = 0; actualIndex < count; ++actualIndex)
            stream << actual[actualIndex] << " ";
        stream << "]";

        results.OnTestFailure(details, stream.GetText());
        return false;
    }
    return true;
}

template< typename Expected, typename Actual, typename Tolerance >
bool CheckArray2DClose(TestResults& results, Expected const& expected, Actual const& actual,
                   int const rows, int const columns, Tolerance const& tolerance, TestDetails const& details)
{
    bool equal = true;
    for (int i = 0; i < rows; ++i)
        equal &= ArrayAreClose(expected[i], actual[i], columns, tolerance);

    if (!equal)
    {
        UnitTest::MemoryOutStream stream;

        stream << "Expected [ ";    

		for (int expectedRow = 0; expectedRow < rows; ++expectedRow)
        {
            stream << "[ ";
            for (int expectedColumn = 0; expectedColumn < columns; ++expectedColumn)
                stream << expected[expectedRow][expectedColumn] << " ";
            stream << "] ";
        }

		stream << "] +/- " << tolerance << " but was [ ";

		for (int actualRow = 0; actualRow < rows; ++actualRow)
        {
            stream << "[ ";
            for (int actualColumn = 0; actualColumn < columns; ++actualColumn)
                stream << actual[actualRow][actualColumn] << " ";
            stream << "] ";
        }

		stream << "]";

        results.OnTestFailure(details, stream.GetText());
        return false;
    }
    return true;
}

template<typename HaystackIterator, typename Needle>
bool CheckContains(TestResults& results, HaystackIterator begin, HaystackIterator end, Needle needle, TestDetails const& details)
{
    if (std::find(begin, end, needle) == end)
    {
        UnitTest::MemoryOutStream message;

        // Make sure the message starts with the text "Expected" so that the ConsoleTestReporter will print it.
        message << "Expected to find '" << needle << "', but it was not there.\n";
        message << "Collection count: " << std::distance(begin, end) << std::endl;
        message << "The first few:\n";
        int i = 0;
        HaystackIterator it = begin;
        while (it != end && i < 3)
        {
            message << "\t'" << *it << "'\n";
            ++it;
            ++i;
        }

        results.OnTestFailure(details, message.GetText());
        return false;
    }
    return true;
}

}

#endif
