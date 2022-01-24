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

    bool InitSdl(Uint32 flags);
    bool InitTtf();
}