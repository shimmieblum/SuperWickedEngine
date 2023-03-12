#pragma once
#include "SuperWickedEngine/Core.h"
#include "SuperWickedEngine/Events/Event.h"


namespace SuperWickedEngine {

// To implement a Layer simply implement this header file. 
    class SWE_API Layer
    {
    public:
        Layer(const std::string& debugName = "Layer");
        virtual ~Layer();
            
        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        [[nodiscard]] const std::string& GetName() const { return m_DebugName; }
    protected:
        std::string m_DebugName;
    };
}
