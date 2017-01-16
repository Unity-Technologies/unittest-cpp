#ifndef UNITTEST_TYPEHELPERS_H
#define UNITTEST_TYPEHELPERS_H

#include "MemoryOutStream.h"

namespace UnitTest {

	namespace detail
	{
		typedef char NoType;
		typedef char YesType[2];
		
		struct MatchAnyType {
			template<typename T> MatchAnyType( T const& );
		};
		
		// Types without insertion operators defined will match this operator instead
		// The return type can then be tested to check whether this was matched or not
		NoType operator<<( std::ostream const&, MatchAnyType const& );
		
		YesType& test( std::ostream& );
		NoType test( NoType );
		
		template<typename T>
		struct HasInsertionOperator {
			static std::ostream &s;
			static T const &t;
			static bool const value = sizeof( test(s << t) ) == sizeof( YesType );
		};
		
		template<bool HasOperator, typename T>
		struct Stringifier;
		
		template<typename T>
		struct Stringifier<true, T>
		{
			static std::string Stringify(T const& value, const char* defaultValue = NULL)
			{
				// Silence any 'unused variable' warnings about defaultValue
				do { if (false) (void)(defaultValue); } while(0);
					
				UnitTest::MemoryOutStream str;
				str << value;
				return str.GetText();
			}
		};
		
		template<typename T>
		struct Stringifier<false, T>
		{
			static std::string Stringify(T const&, const char* defaultValue = "<cannot display value>")
			{
				UnitTest::MemoryOutStream str;
				str << defaultValue;
				return str.GetText();
			}
		};
	}
	
	template<typename T>
	struct TypeHelpers : public detail::Stringifier<detail::HasInsertionOperator<T>::value, T>
	{
		
	};
}

#endif
