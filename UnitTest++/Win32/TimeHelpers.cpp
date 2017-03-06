#include "TimeHelpers.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace UnitTest {

Timer::Timer() : m_startTime(0)
{
	::QueryPerformanceFrequency(reinterpret_cast< LARGE_INTEGER* >(&m_frequency));
}

void Timer::Start()
{
	m_startTime = GetTime();
}

double Timer::GetTimeInMs() const
{
	__int64 const elapsedTime = GetTime() - m_startTime;
	double const seconds = double(elapsedTime) / double(m_frequency);
	return seconds * 1000.0;
}

__int64 Timer::GetTime() const
{
	LARGE_INTEGER curTime;
	::QueryPerformanceCounter(&curTime);
	return curTime.QuadPart;
}

void TimeHelpers::SleepMs(int ms)
{
	::Sleep(ms);
}

}
