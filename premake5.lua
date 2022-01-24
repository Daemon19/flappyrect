workspace "flappybird"
    configurations {"Debug", "Release"}

project "flappybird"
    kind "WindowedApp"
    language "C++"
    location "build"
    targetdir "build/bin/%{cfg.buildcfg}"

    includedirs {"include"}
    links {"SDL2main", "SDL2"}
    files {"**.h", "**.cc"}

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"