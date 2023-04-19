#pragma once
#ifdef HZ_PLATFORM_WINOWS
	#ifdef HZ_BUGLD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error hazel only supprt window
#endif // 

