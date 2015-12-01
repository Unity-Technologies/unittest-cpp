#pragma once

#include <map>
#include <string>

namespace UnitTest
{

class TestProperty
{
public:
// 	enum ResultType
// 	{
// 		kMemoryPeak = 0,     //!< Maximum memory usage during test execution (bytes).
// 		kMemoryUsed,         //!< Used memory after a test (bytes).
// 		kMemoryReserved,     //!< Reserved memory after a test (bytes).
// 		kTestTime,           //!< Test body execution time (ns).
// 	};

	enum Type
	{
		kInt = 0,
		kLong,
		kFloat,
		kDouble,
		kString
	};

	TestProperty() : type(kInt) { intValue = 0; }
	TestProperty(int value) : type(kInt) { intValue = value; }
	TestProperty(long long value) : type(kLong) { longValue = value; }
	TestProperty(float value) : type(kFloat) { floatValue = value; }
	TestProperty(double value) : type(kDouble) { doubleValue = value; }
	TestProperty(const char* value) : type(kString) { stringValue = value; }

	operator std::string() const
	{
		return AsString();
	}

	std::string AsString() const
	{
		switch (type)
		{
		case kInt: return AsStringHelper("%i", intValue);
		case kLong: return AsStringHelper("%lli", longValue);
		case kFloat: return AsStringHelper("%f", floatValue);
		case kDouble: return AsStringHelper("%f", doubleValue);
		case kString: return stringValue;
		}
	}

	Type type;
	union 
	{
		int intValue;
		long long longValue;
		float floatValue;
		double doubleValue;
	};
	std::string stringValue;

private:
	template<typename T>
	static std::string AsStringHelper(const char* fmt, T value)
	{
		char buf[255];
#ifdef WIN32
		_snprintf
#else
		snprintf
#endif
			(buf, sizeof(buf), fmt, value);
		return buf;
	}
};

typedef std::map<std::string, TestProperty> TestProperties;

}
