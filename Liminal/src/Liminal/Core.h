#pragma once

#ifdef LM_PLATFORM_WINDOWS
	#ifdef LM_BUILD_DLL
		#define LIMINAL_API __declspec(dllexport)
	#else
		#define LIMINAL_API __declspec(dllimport)
	#endif
#else
	#error Liminal only support Windows!
#endif