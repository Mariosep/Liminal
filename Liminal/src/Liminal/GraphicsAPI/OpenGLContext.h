#pragma once

#include "../Core.h"
#include "IGraphicsContext.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Liminal
{
	class LIMINAL_API OpenGLContext : public IGraphicsContext
	{
	public:
		OpenGLContext(int width, int height, const char* title);
		~OpenGLContext();
		// Initialize GLFW and glad, create window and configure OpenGL context
		bool Init() override;
		// Returns true if window is still open
		bool ShouldKeepRunning() override;
		void SwapBuffersAndPollEvents() override;
		inline GLFWwindow* GetWindow() { return window; }
	private:
		int windowWidth;
		int windowHeight;
		const char* windowTitle;
		GLFWwindow* window;
	};
}
