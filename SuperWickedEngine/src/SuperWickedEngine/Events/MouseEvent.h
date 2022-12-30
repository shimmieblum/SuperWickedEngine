#pragma once
#include <string>
#include <functional>
#include <sstream>

#include "Event.h"

namespace SuperWickedEngine
{
    class SWE_API MouseEvent : public Event
    {
    public:
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseEvent() = default;
    };
    
    class SWE_API MouseMovedEvent : public MouseEvent
    {
    public:
        MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

        float GetMouseX() const {return  m_MouseX; }
        float GetMouseY() const { return m_MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseMoved)
    private:
        float m_MouseX, m_MouseY;
    };

    class SWE_API MouseScrolledEvent : public MouseEvent
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

        float GetXOffset() const { return m_XOffset; }
        float GetYOffset() const { return m_YOffset; }

        EVENT_CLASS_TYPE(MouseScrolled)
    private:
        float m_XOffset, m_YOffset;
    };

    class SWE_API MouseButtonEvent : public MouseEvent
    {
    public:

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonEvent button: " << m_Button;
            return ss.str();
        }

        int GetButton() const { return  m_Button; }

    protected:
        MouseButtonEvent(int button): m_Button(button) {}
        
        int m_Button;
    };

    class SWE_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class SWE_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}
