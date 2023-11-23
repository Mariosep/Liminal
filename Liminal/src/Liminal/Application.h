#pragma once

#include "Core.h"
#include "GraphicsAPI/IGraphicsContext.h"
#include "GraphicsAPI/OpenGLContext.h"
#include "LayerStack.h"

namespace Liminal
{
	class LIMINAL_API Application
	{
	public:
		Application(int width, int height, const char* title);
		virtual ~Application() = default;
		
		void Run();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline GLFWwindow* GetWindow() { return graphicsContext.GetWindow(); }
		static inline Application& Get() { return *instance; }
	private:
		// TODO: Encapsulate window info in Window class
		int windowWidth;
		int windowHeight;
		const char* windowTitle;
		OpenGLContext graphicsContext;

		bool running = true;
		LayerStack layerStack;
	private:
		static Application* instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
