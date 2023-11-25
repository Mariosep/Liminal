#pragma once

#include "lmpch.h"
#include "Liminal/Core.h"
#include "Liminal/Renderer/OpenGLContext.h"

namespace Liminal
{
	struct WindowProps 
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& title = "Liminal Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
			: title(title), width(width), height(height) {}
	};

	class Window
	{
	public:
		Window(const WindowProps& props);
		~Window();

		void OnUpdate();

		inline unsigned int GetWidth() const { return m_Data.width; }
		inline unsigned int GetHeight() const { return m_Data.height; }

		// Window attributes 
		inline void SetEventCallback(/*const EventCallbackFn& callback*/) /*{ data.eventCallback = callback }*/;
		void SetVSync(bool enabled);
		bool IsVSync() const;

		static Window* Create(const WindowProps& props = WindowProps());
	private:
		void Init(const WindowProps& props);
		void Shutdown();
	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vsync;

			//EventCallbackFn eventCallback;
		};

		WindowData m_Data;
	};
}
