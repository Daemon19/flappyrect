#pragma once

#include <SDL2/SDL.h>

namespace candy
{
    class Init
    {
    private:
        static Init instance_;

        Init() {}
        ~Init();
    };

    enum InitFlag
    {
        kInitVideo = SDL_INIT_VIDEO
    };

    bool InitSdl(InitFlag flags);
}