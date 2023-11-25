#pragma once

#include "Core.h"
#include "Liminal/Window.h"
#include "Liminal/LayerStack.h"
#include "Liminal/UI/ImGuiLayer.h"

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

		inline Window& GetWindow() { return *m_Window; }
		static inline Application& Get() { return *instance; }
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	private:
		static Application* instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
