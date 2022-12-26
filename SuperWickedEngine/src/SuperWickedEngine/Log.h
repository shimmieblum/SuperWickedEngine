#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
namespace SuperWickedEngine
{
    class SWE_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){ return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

    };
    
}

#define SWE_CORE_ERROR(...)     ::SuperWickedEngine::Log::GetCoreLogger()->error(__VA_ARGS__) 
#define SWE_CORE_WARN(...)      ::SuperWickedEngine::Log::GetCoreLogger()->warn(__VA_ARGS__) 
#define SWE_CORE_INFO(...)      ::SuperWickedEngine::Log::GetCoreLogger()->info(__VA_ARGS__) 
#define SWE_CORE_TRACE(...)     ::SuperWickedEngine::Log::GetCoreLogger()->trace(__VA_ARGS__) 
#define SWE_CORE_FATAL(...)     ::SuperWickedEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__) 

#define SWE_ERROR(...)     ::SuperWickedEngine::Log::GetClientLogger()->error(__VA_ARGS__) 
#define SWE_WARN(...)      ::SuperWickedEngine::Log::GetClientLogger()->warn(__VA_ARGS__) 
#define SWE_INFO(...)      ::SuperWickedEngine::Log::GetClientLogger()->info(__VA_ARGS__) 
#define SWE_TRACE(...)     ::SuperWickedEngine::Log::GetClientLogger()->trace(__VA_ARGS__) 
#define SWE_FATAL(...)     ::SuperWickedEngine::Log::GetClientLogger()->fatal(__VA_ARGS__) 