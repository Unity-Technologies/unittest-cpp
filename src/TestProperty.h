#pragma once

#include "MemoryOutStream.h"

#include <map>
#include <string>

namespace UnitTest
{

// Simple "variant"-like property which is used to store custom test data.
class TestProperty
{
public:
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
		MemoryOutStream stream;
		switch (type)
		{
		case kInt: stream << intValue; break;
		case kLong: stream << longValue; break;
		case kFloat: stream << floatValue; break;
		case kDouble: stream << doubleValue; break;
		case kString: return stringValue;
		}
		return stream.GetText();
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
};

typedef std::map<std::string, TestProperty> TestProperties;

}
