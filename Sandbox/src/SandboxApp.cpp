#include "SuperWickedEngine.h"

class Sandbox : public swe::Application
{
public:
    Sandbox()
    { }

    ~Sandbox()
    { }
};

swe::Application* swe::CreateApplication()
{
    return new Sandbox();
}

