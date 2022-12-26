#pragma once
#include "Log.h"

# ifdef SWE_PLATFORM_WINDOWS

namespace SuperWickedEngine
{
    class Log;
}

extern SuperWickedEngine::Application* SuperWickedEngine::CreateApplication();

int main(int argc, char** argv)
{
    SuperWickedEngine::Log::Init();
    SWE_CORE_WARN("Logging Started");
    SWE_INFO("Welcome to the SuperWickedEngine Logger");
    
    auto app = SuperWickedEngine::CreateApplication();
    app->run();
    delete app;
}


#endif
