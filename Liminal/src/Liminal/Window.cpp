#include "lmpch.h"
#include "Window.h"

namespace Liminal
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new Window(props);
	}

	Window::Window(const WindowProps& props)
	{
		Init(props);
	}

	Window::~Window() 
	{
		Shutdown();
	}

	void Window::Init(const WindowProps& props)
	{
		data.title = props.title;
		data.width = props.width;
		data.height = props.height;

		LM_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			LM_CORE_ASSERT(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &data);
		SetVSync(true);

		int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		LM_CORE_ASSERT(success, "Could not initialize GLAD");
	}

	void Window::OnUpdate()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		data.vsync = enabled;
	}

	bool  Window::IsVSync() const
	{
		return data.vsync;
	}

	void Window::Shutdown()
	{
		glfwDestroyWindow(window);
	}
}