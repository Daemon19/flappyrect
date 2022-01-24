#include <SDL2/SDL.h>
#include <vector>

#include "candy/candy.h"
#include "player.h"
#include "wall_handler.h"

int main(int argc, char *argv[])
{
    using namespace candy;

    InitSdl(SDL_INIT_VIDEO);

    Window window;
    window.Init("Flappy Bird", 525, 700);

    Player player(100, (window.h() - Player::kSize) / 2);

    WallHandler wall_handler(window.w(), window.h(), 1000);

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
        wall_handler.Update();

        if (wall_handler.CollideRect(player.rect()))
        {
            player.Reset();
            wall_handler.Reset();
        }

        SDL_SetRenderDrawColor(window, 10, 10, 25, 255);
        SDL_RenderClear(window);

        SDL_SetRenderDrawColor(window, 255, 50, 50, 255);
        wall_handler.Draw(window);

        SDL_SetRenderDrawColor(window, 255, 255, 255, 255);
        player.Draw(window);

        SDL_RenderPresent(window);
    }

    return 0;
}
