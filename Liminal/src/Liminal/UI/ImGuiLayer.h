#pragma once

#include "Liminal/Core.h"
#include "Liminal/Layer.h"

namespace Liminal
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent() override;
	private:
		float m_Time = 0.0f;
	};
}
