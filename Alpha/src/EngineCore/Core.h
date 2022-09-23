#pragma once

#ifdef ALPHA_PLATFORM_WINDOWS
	#ifdef ALPHA_BUILD_DLL
		#define ALPHA_API __declspec(dllexport)
	#else
		#define ALPHA_API __declspec(dllimport)
	#endif
#else
	#error Alpha only supports Windows.
#endif

#ifdef ALPHA_ENABLE_ASSERTS
	#define ALPHA_ASSERT(x, ...) {if (!(x)) {LOG_ERROR("Assertion Failed: {0}" __VA_ARGS__); __debugbreak(); } }
	#define ALPHA_CORE_ASSERT(x, ...) {if (!(x)) {LOG_CORE_ERROR("Assertion Failed: {0}" __VA_ARGS__); __debugbreak(); } }
#else
	#define ALPHA_ASSERT(x, ...)
	#define ALPHA_CORE_ASSERT(x, ...)
#endif
#define BIT(x) (1 << x)