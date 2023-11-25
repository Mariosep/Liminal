#pragma once

#include "Core.h"
#include "Liminal/Window.h"
#include "Liminal/LayerStack.h"

namespace Liminal
{
	class Application
	{
	public:
		Application();
		virtual ~Application() = default;
		
		void Run();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *window; }
		static inline Application& Get() { return *instance; }
	private:
		std::unique_ptr<Window> window;
		bool running = true;
		LayerStack layerStack;
	private:
		static Application* instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
