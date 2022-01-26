#pragma once

#include <SDL2/SDL_ttf.h>
#include <string>

#include "texture.h"

namespace candy
{
    class Font
    {
    private:
        TTF_Font *font_ = nullptr;

    public:
        Font(const Font &) = delete;
        Font() = default;
        ~Font();

        bool Load(const std::string &filepath, int size);
        bool RenderText(const std::string &text,
                        const SDL_Color &color,
                        SDL_Renderer *renderer,
                        Texture &dst_texture);

        operator TTF_Font *() { return font_; }

    private:
        void Free();
    };
}