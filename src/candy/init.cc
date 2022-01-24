#include <SDL2/SDL.h>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "init.h"

namespace candy
{
    Init Init::instance_;

    Init::~Init()
    {
        SDL_Quit();
        TTF_Quit();
    }

    bool InitSdl(Uint32 flags)
    {
        if (SDL_Init(flags) < 0)
        {
            std::cerr << "Gagal menginisialisasi SDL : " << SDL_GetError()
                      << std::endl;
            return false;
        }
        return true;
    }

    bool InitTtf()
    {
        if (TTF_Init() < 0)
        {
            std::cerr << "Gagal menginisialisasi SDL_Ttf : " << TTF_GetError()
                      << std::endl;
            return false;
        }
        return true;
    }
}
