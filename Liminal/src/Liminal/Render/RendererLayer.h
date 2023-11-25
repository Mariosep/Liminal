#pragma once

#include "Liminal/Layer.h"

namespace Liminal
{
	class RendererLayer : public Layer
	{
	public:

		RendererLayer();
		~RendererLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent() override;

		// Add rendering-specific functions as needed
		// e.g., renderScene(), renderUI(), etc.
	};
}
