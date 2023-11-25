#pragma once

#include "Core.h"
#include <spdlog/spdlog.h>

namespace Liminal
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define LM_CORE_TRACE(...) ::Liminal::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LM_CORE_INFO(...) ::Liminal::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LM_CORE_WARN(...) ::Liminal::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LM_CORE_ERROR(...) ::Liminal::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LM_CORE_FATAL(...) ::Liminal::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LM_TRACE(...) ::Liminal::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LM_INFO(...) ::Liminal::Log::GetClientLogger()->info(__VA_ARGS__)
#define LM_WARN(...) ::Liminal::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LM_ERROR(...) ::Liminal::Log::GetClientLogger()->error(__VA_ARGS__)
#define LM_FATAL(...) ::Liminal::Log::GetCoreLogger()->fatal(__VA_ARGS__)


