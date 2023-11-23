#pragma once

#include "Liminal/Core.h"

namespace Liminal
{
	class LIMINAL_API IGraphicsContext
	{
	public:
		virtual ~IGraphicsContext() {}
		virtual bool Init() = 0;
		virtual bool ShouldKeepRunning() = 0;
		virtual void SwapBuffersAndPollEvents() = 0;
	};
}
