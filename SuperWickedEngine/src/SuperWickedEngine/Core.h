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

#ifdef SWE_ENABLE_ASSERTS
    #define SWE_ASSERT( x, ...) { if(!(x)) { SWE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define SWE_CORE_ASSERT( x, ...) { if(!(x)) { SWE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define SWE_ASSERT(x, ...)
    #define SWE_CORE_ASSERT( x, ...)
#endif


#define BIT(x) (1 << (x)) // bitfield
