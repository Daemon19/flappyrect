#pragma once

#include <SDL2/SDL.h>

namespace candy
{
    class Texture
    {
    private:
        SDL_Texture *texture_ = nullptr;
        Uint32 format_;
        int access_;
        int w_;
        int h_;

    public:
        Texture(const Texture &) = delete;
        Texture() = default;
        ~Texture();

        bool Init(SDL_Texture *texture);

        operator SDL_Texture *() { return texture_; }

        int w() const { return w_; }
        int h() const { return h_; }

    private:
        void Free();
    };
}