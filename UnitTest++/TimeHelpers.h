#include "Config.h"

#if defined (UNITTEST_BASELIB)
    #include "TimeHelpersBaselib.h"
#elif defined (UNITTEST_POSIX)
    #include "Posix/TimeHelpers.h"
#elif defined(_MSC_VER)
    #include "Win32/TimeHelpers.h"

#else // dummy impl
namespace UnitTest {

    class Timer
    {
        Timer() {}
        void Start() {}
        double GetTimeInMs() const { return 0; }
    }

    namespace TimeHelpers
    {
        void SleepMs(int const ms) {}
    }
}
#endif
