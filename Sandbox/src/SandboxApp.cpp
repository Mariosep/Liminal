#include <Liminal.h>
#include <string>
#include <iostream>

class ExampleLayer : public Liminal::Layer
{
public:
	ExampleLayer() {}

	void OnUpdate() override
	{
		std::cout << "ExampleLayer::Update" << std::endl;
	}
};

class Sandbox : public Liminal::Application
{
public:
	Sandbox() : Liminal::Application()
	{
		//PushLayer(new ExampleLayer());
		PushOverlay(new Liminal::ImGuiLayer());
	}

	using Liminal::Application::Application;
};

Liminal::Application* Liminal::CreateApplication()
{
	return new Sandbox();
}