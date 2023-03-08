#include "swepch.h"

#include "Application.h"

#include "Log.h"


namespace SuperWickedEngine
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

    Application::Application()
     {
         m_Window = std::unique_ptr<Window>(Window::Create());
         m_Window-> SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
     }

     Application::~Application() = default;

    void Application::OnEvent(Event& e)
    {
        SWE_CORE_INFO("{0}", e);
    }

     void Application::Run() const
     {
         while(m_Running)
         {
             m_Window->OnUpdate();
         }
        
     }
}
