#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

#include "candy/candy.h"
#include "player.h"
#include "wall_handler.h"

int main(int argc, char *argv[])
{
    using namespace candy;

    InitSdl(SDL_INIT_VIDEO);
    InitTtf();

    Window window;
    // window.Init("Flappy Bird", 525, 700);
    window.Init("Flappy Bird", 480, 640);

    Player player(100, (window.h() - Player::kSize) / 2);

    Font score_font;
    score_font.Load("res/score_font.ttf", 64);

    Texture score_texture;
    score_font.RenderText(std::to_string(player.score()).c_str(),
                          {255, 255, 255, 255}, window, score_texture);
    int last_score = player.score();

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

        if (wall_handler.CollideRect(player.rect()) ||
            player.rect().y > window.h())
        {
            player.Reset();
            wall_handler.Reset();
        }

        if (wall_handler.CheckPassed(player.rect()))
            player.add_score();

        if (last_score != player.score())
        {
            score_font.RenderText(std::to_string(player.score()).c_str(),
                                  {255, 255, 255, 255}, window, score_texture);
            last_score = player.score();
        }

        SDL_SetRenderDrawColor(window, 10, 10, 25, 255);
        SDL_RenderClear(window);

        SDL_SetRenderDrawColor(window, 255, 50, 50, 255);
        wall_handler.Draw(window);

        SDL_SetRenderDrawColor(window, 255, 255, 255, 255);
        player.Draw(window);

        int w = score_texture.w();
        int h = score_texture.h();
        SDL_Rect score_rect = {(window.w() - w) / 2,
                               50, w, h};
        SDL_RenderCopy(window, score_texture, nullptr, &score_rect);

        SDL_RenderPresent(window);
    }

    return 0;
}
