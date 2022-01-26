workspace "flappyrect"
    configurations {"Debug", "Release"}

project "flappyrect"
    kind "WindowedApp"
    language "C++"
    location "build"
    targetdir "build/bin/%{cfg.buildcfg}"

    includedirs {"include", "include/candy"}
    links {"SDL2main", "SDL2", "SDL2_ttf"}
    files {"**.h", "**.cc"}

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"