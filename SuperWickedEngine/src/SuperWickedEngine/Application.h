#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "LayerSystem/Layer.h"
#include "LayerSystem/LayerStack.h"


namespace SuperWickedEngine
{
    class  SWE_API Application
    {
        
    public:
        Application();
        virtual ~Application();
        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        bool OnWindowClose(WindowCloseEvent& e);
        LayerStack m_LayerStack;


    };
    
    // To Be Defined in client
    Application* CreateApplication();
}
    
