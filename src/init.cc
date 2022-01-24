#include <SDL2/SDL.h>
#include <iostream>

#include "init.h"

namespace candy
{
    Init Init::instance_;

    Init::~Init()
    {
        SDL_Quit();
    }

    bool InitSdl(InitFlag flags)
    {
        if (SDL_Init(flags) < 0)
        {
            std::cerr << "Gagal menginisialisasi SDL : " << SDL_GetError()
                      << std::endl;
            return false;
        }
        return true;
    }
}
