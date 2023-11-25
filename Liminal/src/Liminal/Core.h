#pragma once

#ifdef LM_PLATFORM_WINDOWS
#else
	#error Liminal only support Windows!
#endif

#ifdef LM_ENABLE_ASSERTS
	#define LM_ASSERT(x, ...) { if(!(x)) { LM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }	
	#define LM_CORE_ASSERT(x, ...) { if(!(x)) { LM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }	
#else
	#define LM_ASSERT(x, ...)
	#define LM_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)