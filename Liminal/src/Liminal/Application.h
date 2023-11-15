#pragma once

#include "Core.h"

namespace Liminal
{
	class LIMINAL_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
