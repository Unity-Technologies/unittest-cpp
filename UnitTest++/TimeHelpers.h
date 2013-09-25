#include "Config.h"

#if defined UNITTEST_POSIX
    #include "Posix/TimeHelpers.h"
#elif defined(_MSC_VER)
    #include "Win32/TimeHelpers.h"
#else
    #include "TimeHelpersDefault.h"
#endif
