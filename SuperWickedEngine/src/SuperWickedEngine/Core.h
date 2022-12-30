#pragma once

#ifdef SWE_PLATFORM_WINDOWS
    #ifdef SWE_BUILD_DLL
        #define SWE_API __declspec(dllexport)
    #else
        #define SWE_API __declspec(dllimport)
    #endif
#else
    #error SuperWickedEngine only works on windows
#endif

#define BIT(x) (1 << (x)) // bitfield
