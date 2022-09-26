#pragma once

#ifdef ALPHA_PLATFORM_WINDOWS
	#if ALPHA_DYNAMIC_LINK
		#ifdef ALPHA_BUILD_DLL
			#define ALPHA_API __declspec(dllexport)
		#else
			#define ALPHA_API __declspec(dllimport)
		#endif
	#else
		#define ALPHA_API
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

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#define BIT(x) (1 << x)