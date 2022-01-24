#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace candy
{
    class Window
    {
    private:
        SDL_Window *window_ = nullptr;
        SDL_Renderer *renderer_ = nullptr;

        int w_;
        int h_;

    public:
        Window() = default;
        ~Window();

        bool Init(const std::string &title, int w, int h);

        operator SDL_Window *() { return window_; }
        operator SDL_Renderer *() { return renderer_; }

        int w() { return w_; }
        int h() { return h_; }

    private:
        void Free();
    };
}