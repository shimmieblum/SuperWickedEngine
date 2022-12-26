#pragma once
#include "Core.h"


namespace SuperWickedEngine
{
    
    class  SWE_API Application
    {
        
    public:
        Application();
        virtual ~Application();
        void run();
    };


    // To Be Defined in client
    Application* CreateApplication();
}
    
