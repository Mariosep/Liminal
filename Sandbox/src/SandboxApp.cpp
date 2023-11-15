#include <Liminal.h>

class Sandbox : public Liminal::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Liminal::Application* Liminal::CreateApplication()
{
	return new Sandbox();
}