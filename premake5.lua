workspace "SuperWickedEngine"
    architecture "x64"
    
    configurations{
        "Debug", 
        "Release", 
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "SuperWickedEngine/vendor/GLFW/include"

include "SuperWickedEngine/vendor/GLFW"


project "SuperWickedEngine"
    location "SuperWickedEngine"
    kind "SharedLib"
    language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "swepch.h"
    pchsource "SuperWickedEngine/src/swepch.cpp"
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows" 
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SWE_PLATFORM_WINDOWS",
            "SWE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")

        }
    
    filter "configurations:Debug"
        defines "SWE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "SWE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SWE_DIST"
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
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "SuperWickedEngine/vendor/spdlog/include",
        "SuperWickedEngine/src"
    }

    filter "system:windows" 
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SWE_PLATFORM_WINDOWS"
        }
    
    links
    {
        "SuperWickedEngine"
    }

    filter "configurations:Debug"
        defines "SWE_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "SWE_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "SWE_DIST"
        buildoptions "/MD"
        optimize "On"

    