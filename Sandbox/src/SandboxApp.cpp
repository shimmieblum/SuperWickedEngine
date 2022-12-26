#include "SuperWickedEngine.h"

class Sandbox : public SuperWickedEngine::Application
{
public:
    Sandbox()
    {
    }

    ~Sandbox()
    { }
};

SuperWickedEngine::Application* SuperWickedEngine::CreateApplication()
{
    return new Sandbox();
}

