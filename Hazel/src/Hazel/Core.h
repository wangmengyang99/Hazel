#pragma once
#ifdef HZ_PLATFORM_WINOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error hazel only supprt window
#endif // 
#define BIT(x) 1<<x
