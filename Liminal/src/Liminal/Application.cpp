#include "lmpch.h"
#include "Application.h"

namespace Liminal
{
	Application* Application::instance = nullptr;

	Application::Application(int width, int height, const char* title)
		: windowWidth(width), windowHeight(height), windowTitle(title), graphicsContext(width, height, title) 
	{
		instance = this;

		if (!graphicsContext.Init())
		{
			std::cerr << "Failed to initialize the graphics context." << std::endl;
			return;
		}
	}

	void Liminal::Application::Run()
	{
		while (graphicsContext.ShouldKeepRunning())
		{
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack)
				layer->OnUpdate();

			// Swap buffers and handle events
			graphicsContext.SwapBuffersAndPollEvents();
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
