#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"


namespace SuperWickedEngine
{
    
    class  SWE_API Application
    {
        
    public:
        Application();
        virtual ~Application();
        void Run() const;

        void OnEvent(Event& e);
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        bool OnWindowClose(WindowCloseEvent& e);


    };
    
    // To Be Defined in client
    Application* CreateApplication();
}
    
