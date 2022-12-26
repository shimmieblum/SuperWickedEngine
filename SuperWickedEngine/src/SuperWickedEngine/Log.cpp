#include "Log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace SuperWickedEngine
{

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n (%l): %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("SUPER_WICKED_ENGINE");
        s_CoreLogger -> set_level(spdlog::level::trace);
        
        s_ClientLogger = spdlog::stderr_color_mt("APP");
        s_ClientLogger -> set_level(spdlog::level::trace);
    }

    

}
