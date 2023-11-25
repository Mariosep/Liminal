#pragma once

#include "Liminal/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Liminal
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		void Init() override;
		void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}
