#ifndef UNITTEST_TIMEHELPERSDEFAULT_H
#define UNITTEST_TIMEHELPERSDEFAULT_H

#include "Config.h"

namespace UnitTest {

class Timer
{
public:
    Timer();
	void Start();
	int GetTimeInMs() const;

private:
};


namespace TimeHelpers
{
void SleepMs (int ms);
}


}



#endif
