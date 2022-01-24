#include <SDL2/SDL.h>

#include "candy/candy.h"
#include "player.h"

int main(int argc, char *argv[])
{
    using namespace candy;

    InitSdl(SDL_INIT_VIDEO);

    Window window;
    window.Init("Flappy Bird", 960, 540);

    Player player({100, 0, 60, 60});

    bool game_running = true;
    while (game_running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                game_running = false;
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                    player.Jump();
            }
        }

        player.Update();

        SDL_SetRenderDrawColor(window, 10, 10, 25, 255);
        SDL_RenderClear(window);
        SDL_SetRenderDrawColor(window, 255, 255, 255, 255);
        player.Draw(window);
        SDL_RenderPresent(window);
    }

    return 0;
}
