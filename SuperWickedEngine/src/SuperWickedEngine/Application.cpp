#include "swepch.h"

#include "Application.h"


namespace SuperWickedEngine
{
     Application::Application()
     {
         m_Window = std::unique_ptr<Window>(Window::Create());
     }

     Application::~Application() = default;

     void Application::Run() const
     {
         while(m_Running)
         {
             m_Window->OnUpdate();
         }
        
     }
}