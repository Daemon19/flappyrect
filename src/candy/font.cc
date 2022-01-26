#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "font.h"
#include "texture.h"

namespace candy
{
    Font::~Font()
    {
        Free();
    }

    bool Font::Load(const std::string &filepath, int size)
    {
        TTF_Font *tmp = TTF_OpenFont(filepath.c_str(), size);
        if (tmp == nullptr)
        {
            std::cerr << "Gagal memuat font : " << TTF_GetError() << std::endl;
            return false;
        }

        Free();
        font_ = tmp;
        return true;
    }

    bool Font::RenderText(const std::string &text,
                          const SDL_Color &color,
                          SDL_Renderer *renderer,
                          Texture &dst_texture)
    {
        SDL_Surface *text_surface = TTF_RenderText_Blended(font_, text.c_str(), color);
        if (text_surface == nullptr)
        {
            std::cerr << "Gagal membuat texture : " << TTF_GetError()
                      << std::endl;
            return false;
        }

        return dst_texture.Init(SDL_CreateTextureFromSurface(renderer, text_surface));
    }

    void Font::Free()
    {
        if (font_ != nullptr)
            TTF_CloseFont(font_);
    }
}