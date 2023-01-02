#include "swepch.h"
#include "WindowsWindow.h"

#include "SuperWickedEngine/Log.h"

namespace SuperWickedEngine
{
    static bool s_GLFWInitialized = false;

    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        WindowsWindow::Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
        WindowsWindow::Shutdown();
    }

    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Height = props.Height;
        m_Data.Width = props.Width;

        SWE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            SWE_CORE_ASSERT(success, "Couldn't initialize GLFW")
            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow(
            static_cast<int>(props.Width),
            static_cast<int>(props.Height),
            m_Data.Title.c_str(),
            nullptr,
            nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if(enabled)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }
        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }







    
}
