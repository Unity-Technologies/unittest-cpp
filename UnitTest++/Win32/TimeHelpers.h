#ifndef UNITTEST_TIMEHELPERS_H
#define UNITTEST_TIMEHELPERS_H

#include "../Config.h"
#include "../HelperMacros.h"

#ifdef UNITTEST_MINGW
    #ifndef __int64
        #define __int64 long long
    #endif
#endif

namespace UnitTest {

class UNITTEST_LINKAGE Timer
{
public:
    Timer();
	void Start();
	double GetTimeInMs() const;    

private:
    __int64 GetTime() const;

	__int64 m_startTime;
	__int64 m_frequency;
};


namespace TimeHelpers
{
	UNITTEST_LINKAGE void SleepMs(int ms);
}

}

#endif
