#include "texture.h"

#include <SDL2/SDL.h>
#include <iostream>

namespace candy
{
    Texture::~Texture()
    {
        Free();
    }

    bool Texture::Init(SDL_Texture *texture)
    {
        if (texture == nullptr)
        {
            std::cerr << "Gagal membuat menginisalisasi Texture : parameter texture tidak boleh NULL"
                      << std::endl;
            return false;
        }

        if (SDL_QueryTexture(texture, &format_, &access_, &w_, &h_) < 0)
        {
            std::cerr << "Gagal mengambil data texture : " << SDL_GetError()
                      << std::endl;
            return false;
        }

        Free();
        texture_ = texture;
        return true;
    }

    void Texture::Free()
    {
        if (texture_ != nullptr)
            SDL_DestroyTexture(texture_);
    }
}