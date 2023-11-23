#pragma once

#include "Liminal/Core.h"
#include "Liminal/Layer.h"

namespace Liminal
{
	class LIMINAL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent() override;
	};
}
