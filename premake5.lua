workspace "Hazel"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }
    
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "Hazel"
    location "Hazel"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    includedirs{
        "%{prj.name}/vendor/spdlog/include"
    }
    filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
 
   defines 
    {
        " HZ_PLATFORM_WINDOW",
        "HZ_DEBUG_DLL"
    }
  postbuildcommands
   {
	("{COPY} %(cfg.buildtarget.relpath)\" ../bin/" .. outputdir .. "/Sandbox\"")
   }

    filter "configurations:Debug"
    defines "HZ_DEBUG"
    symbols "On"
 
    filter "configurations:Release"
    defines "HZ_RELEASE"
    symbols "On"
 
    filter "configurations:Dist"
    defines "HZ_DIST"
    symbols "On"
project "sandbox"
    location "sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    defines
    {
     "HZ_PLATFORM_WINOWS"
    }
    links
    {
        "Hazel"
    }
    includedirs
	{
        "Hazel/vendor/spdlog/include",
		"Hazel/src"
	}

    filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

        filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"
     
        filter "configurations:Release"
        defines "HZ_RELEASE"
        symbols "On"
     
        filter "configurations:Dist"
        defines "HZ_DIST"
        symbols "On"