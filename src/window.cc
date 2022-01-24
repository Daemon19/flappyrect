#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#include "window.h"

namespace candy
{
    Window::~Window()
    {
        Free();
    }

    bool Window::Init(const std::string &title, int w, int h)
    {
        w_ = w;
        h_ = h;

        window_ = SDL_CreateWindow(title.c_str(),
                                   SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED,
                                   w, h, 0);
        if (window_ == nullptr)
        {
            std::cerr << "Gagal membuat window : " << SDL_GetError() << std::endl;
            return false;
        }

        renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (renderer_ == nullptr)
        {
            std::cerr << "Gagal membuat renderer : " << SDL_GetError() << std::endl;
            Free();
            return false;
        }

        return true;
    }

    void Window::Free()
    {
        if (renderer_ != nullptr)
            SDL_DestroyRenderer(renderer_);
        if (window_ != nullptr)
            SDL_DestroyWindow(window_);
    }
}