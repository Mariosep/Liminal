#pragma once

#include "Liminal/Core.h"

namespace Liminal
{
	class LIMINAL_API Layer
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent() {}

		//inline const std::string& GetName() const { return m_DebugName; }
	//protected:
		//const char* m_DebugName;
	};
}
