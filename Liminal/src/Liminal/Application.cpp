#include "lmpch.h"
#include "Application.h"

namespace Liminal
{
	Application* Application::instance = nullptr;

	Application::Application()
	{
		LM_CORE_ASSERT(!instance, "Application already exists");
		instance = this;

		window = std::unique_ptr<Window>(Window::Create());
	}

	void Liminal::Application::Run()
	{
		while (running)
		{
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack)
				layer->OnUpdate();

			
			window->OnUpdate();
		}
	}
	void Application::PushLayer(Layer* layer)
	{
		layerStack.PushLayer(layer);

	}
	void Application::PushOverlay(Layer* overlay)
	{
		layerStack.PushOverlay(overlay);
	}
}
