#ifndef UNITTEST_SIGNALTRANSLATOR_H
#define UNITTEST_SIGNALTRANSLATOR_H

#include <setjmp.h>

#if __ORBIS__
# include <sys/signal.h>
# define siglongjmp(_env,_sig)		longjmp((_env),(_sig))	// siglongjmp not provided on PS4
# define sigsetjmp(_env,_savesigs)	setjmp((_env))			// sigsetjmp not provided on PS4
# define sigjmp_buf					jmp_buf					// remap sigjmp_buf to jmp_buf
# define sigemptyset(_sa)									// nothing
# define sigaction(_sig, _sa, _oldsig)						// nothing
#else
# include <signal.h>
#endif

namespace UnitTest {

class SignalTranslator
{
public:
    SignalTranslator();
    ~SignalTranslator();

    static sigjmp_buf* s_jumpTarget;

private:
    sigjmp_buf m_currentJumpTarget;
    sigjmp_buf* m_oldJumpTarget;

    struct sigaction m_old_SIGFPE_action;
    struct sigaction m_old_SIGTRAP_action;
    struct sigaction m_old_SIGSEGV_action;
    struct sigaction m_old_SIGBUS_action;
    struct sigaction m_old_SIGABRT_action;
    struct sigaction m_old_SIGALRM_action;
};

#if !defined (__GNUC__)
    #define UNITTEST_EXTENSION
#else
    #define UNITTEST_EXTENSION __extension__
#endif

#if !UNITTEST_USE_EXCEPTIONS
# define UNITTEST_THROW_SIGNALS_POSIX_ONLY	// nothing
#else
#define UNITTEST_THROW_SIGNALS_POSIX_ONLY \
	UnitTest::SignalTranslator sig; \
	if (UNITTEST_EXTENSION sigsetjmp(*UnitTest::SignalTranslator::s_jumpTarget, 1) != 0) \
        throw ("Unhandled system exception"); 
#endif


}


#endif
