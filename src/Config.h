#ifndef UNITTEST_CONFIG_H
#define UNITTEST_CONFIG_H

// Standard defines documented here: http://predef.sourceforge.net

#if defined(_MSC_VER)
    #pragma warning(disable:4127) // conditional expression is constant
	#pragma warning(disable:4702) // unreachable code
	#pragma warning(disable:4722) // destructor never returns, potential memory leak

	#if (_MSC_VER == 1200)  // VC6
		#pragma warning(disable:4786)
		#pragma warning(disable:4290)
	#endif
#endif

#ifndef UNITTEST_FORCE_NO_POSIX
    #if defined(unix) || defined(__unix__) || defined(__unix) || defined(linux) || \
        defined(__APPLE__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__)
        #define UNITTEST_POSIX
    #endif
#endif

#if defined(__MINGW32__)
    #define UNITTEST_MINGW
#endif

#ifdef UNITTEST_FORCE_NO_EXCEPTIONS
    struct
    FakeException
    {
        const char* what() const        { return "<unknown>"; }
        const char* Filename() const    { return "<unknown>"; }
        int LineNumber() const          { return 0; }
    };
    #define HANDLE_FORCED_NO_EXCEPTIONS(name) struct FakeException name;

    #ifdef try
    #undef try
    #endif

    #ifdef catch
    #undef catch
    #endif

    #ifdef True
    #undef True
    #endif


    #define try      if (true)
    #define catch(X) if (false)

#else
    #define HANDLE_FORCED_NO_EXCEPTIONS(name)
#endif


// by default, MemoryOutStream is implemented in terms of std::ostringstream, which can be expensive.
// uncomment this line to use the custom MemoryOutStream (no deps on std::ostringstream).

//#define UNITTEST_USE_CUSTOM_STREAMS

#endif
