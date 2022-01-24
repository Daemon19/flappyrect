#include "candy.h"
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    using namespace candy;

    InitSdl(SDL_INIT_VIDEO);

    Window window;
    window.Init("Flappy Bird", 960, 540);

    bool game_running = true;
    while (game_running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                game_running = false;
        }

        SDL_SetRenderDrawColor(window, 10, 10, 25, 255);
        SDL_RenderClear(window);
        SDL_RenderPresent(window);
    }

    return 0;
}
