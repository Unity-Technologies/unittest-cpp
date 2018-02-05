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
    public:
        inline Timer() {}
        inline void Start() {}
        inline double GetTimeInMs() const { return 0.0; }
    };

    namespace TimeHelpers
    {
        inline void SleepMs(int const ms) {}
    }
}
#endif
