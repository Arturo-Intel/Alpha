workspace "Alpha"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Alpha/vendor/GLFW/Include"
IncludeDir["Glad"] = "Alpha/vendor/Glad/Include"
IncludeDir["ImGui"] = "Alpha/vendor/imgui/"
IncludeDir["glm"] = "Alpha/vendor/glm"


include "Alpha/vendor/GLFW"
include "Alpha/vendor/GLAD"
include "Alpha/vendor/imgui"

project "Alpha"
	location "Alpha"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "alphapch.h"
	pchsource "Alpha/src/alphapch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"Alpha/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
			"GLFW",
			"Glad",
			"ImGui",
			"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines 
		{
			"ALPHA_PLATFORM_WINDOWS",
			"ALPHA_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}


	filter "configurations:Debug"
		defines "ALPHA_DEBUG"
		runtime "Debug"
		symbols "on"
	

	filter "configurations:Release"
		defines "ALPHA_RELEASE"
		runtime "Release"
		optimize "on"
	

	filter "configurations:Dist"
		defines "ALPHA_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"
	cppdialect "C++17"

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
		"Alpha/src",
		"Alpha/vendor/",
		"%{IncludeDir.glm}"

	}

	links
	{
		"Alpha"
	}

	filter "system:windows"
		systemversion "latest"

		defines 
		{
			"ALPHA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ALPHA_DEBUG"
		runtime "Debug"
		symbols "on"
	

	filter "configurations:Release"
		defines "ALPHA_RELEASE"
		runtime "Release"
		optimize "on"
	

	filter "configurations:Dist"
		defines "ALPHA_DIST"
		runtime "Release"
		optimize "on"
