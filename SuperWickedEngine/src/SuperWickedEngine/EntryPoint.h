#pragma once
#include "../SuperWickedEngine.h"

# ifdef SWE_PLATFORM_WINDOWS

extern swe::Application* swe::CreateApplication();

int main(int argc, char** argv)
{
    auto app = swe::CreateApplication();
    app->run();
    delete app;
}


#endif
