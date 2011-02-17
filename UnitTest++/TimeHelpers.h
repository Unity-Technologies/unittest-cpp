#include "Config.h"

#if defined UNITTEST_POSIX
    #include "Posix/TimeHelpers.h"
// Unit-Tests don't include UnityConfigure.h, so we're using RVL define instead of UNITY_WII
#elif defined(RVL)
	#include "Wii/TimeHelpers.h" 
#else
    #include "Win32/TimeHelpers.h"
#endif
