workspace "Alpha"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Alpha"
	location "Alpha"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "alphapch.h"
	pchsource "Alpha/src/alphapch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"Alpha/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"ALPHA_PLATFORM_WINDOWS",
			"ALPHA_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ALPHA_DEBUG"
		symbols "On"
	

	filter "configurations:Release"
		defines "ALPHA_RELEASE"
		optimize "On"
	

	filter "configurations:Dist"
		defines "ALPHA_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Alpha/vendor/spdlog/include",
		"Alpha/src"
	}

	links
	{
		"Alpha"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"ALPHA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ALPHA_DEBUG"
		symbols "On"
	

	filter "configurations:Release"
		defines "ALPHA_RELEASE"
		optimize "On"
	

	filter "configurations:Dist"
		defines "ALPHA_DIST"
		optimize "On"