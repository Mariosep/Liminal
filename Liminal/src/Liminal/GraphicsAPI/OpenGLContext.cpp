#include "lmpch.h"
#include "OpenGLContext.h"

namespace Liminal
{
	OpenGLContext::OpenGLContext(int width, int height, const char* title)
		: windowWidth(width), windowHeight(height), windowTitle(title) {}

	OpenGLContext::~OpenGLContext()
	{
		glfwTerminate();
	}

	bool OpenGLContext::Init()
	{
		// Initialize GLFW
		if (!glfwInit())
		{
			std::cerr << "Failed to initialize GLFW" << std::endl;
			return false;
		}

		// Configure OpenGL context
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// Create window
		window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, nullptr, nullptr);
		if (!window)
		{
			std::cerr << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return false;
		}

		// Configure window context
		glfwMakeContextCurrent(window);

		// Initialize Glad
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return false;
		}

		// Print info about GPU
		std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
		
		return true;
	}

	bool OpenGLContext::ShouldKeepRunning()
	{
		return !glfwWindowShouldClose(window);
	}

	void OpenGLContext::SwapBuffersAndPollEvents()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
