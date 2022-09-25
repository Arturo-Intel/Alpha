workspace "Alpha"
	architecture "x64"
	
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
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "alphapch.h"
	pchsource "Alpha/src/alphapch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
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
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"ALPHA_PLATFORM_WINDOWS",
			"ALPHA_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ALPHA_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	

	filter "configurations:Release"
		defines "ALPHA_RELEASE"
		buildoptions "/MD"
		optimize "On"
	

	filter "configurations:Dist"
		defines "ALPHA_DIST"
		buildoptions "/MD"
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
		"Alpha/src",
		"%{IncludeDir.glm}"
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
		buildoptions "/MDd"
		symbols "On"
	

	filter "configurations:Release"
		defines "ALPHA_RELEASE"
		buildoptions "/MD"
		optimize "On"
	

	filter "configurations:Dist"
		defines "ALPHA_DIST"
		buildoptions "/MD"
		optimize "On"