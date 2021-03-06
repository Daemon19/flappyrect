#include <SDL2/SDL.h>

#include "candy/candy.h"
#include "wall.h"
#include "wall_handler.h"

const int WallHandler::kGapMin = 210;
const int WallHandler::kGapMax = kGapMin + 50;
const int WallHandler::kMinYOff = 100;

WallHandler::WallHandler(int window_w, int window_h, Uint32 create_delay)
    : window_w_(window_w),
      window_h_(window_h),
      create_delay_(create_delay),
      last_create_(SDL_GetTicks())
{
}

void WallHandler::Update()
{
    Uint32 current_ticks = SDL_GetTicks();
    if (current_ticks > last_create_ + create_delay_)
    {
        int gap = candy::Randint(kGapMin, kGapMax);
        int y = candy::Randint(kMinYOff, window_h_ - gap - kMinYOff);

        walls_.emplace_back(Wall(window_w_, y - Wall::kWallH), Wall(window_w_, y + gap));
        last_create_ = current_ticks;
    }

    for (int i = 0; i < walls_.size(); i++)
    {
        walls_.at(i).Update();

        if (walls_.at(i).out_of_frame())
            walls_.erase(walls_.begin() + i--);
    }
}

void WallHandler::Draw(SDL_Renderer *renderer)
{
    for (auto &&w : walls_)
        w.Draw(renderer);
}

bool WallHandler::CollideRect(const SDL_Rect &rect)
{
    for (auto &&w : walls_)
    {
        if (w.CollideRect(rect))
            return true;
    }
    return false;
}

bool WallHandler::CheckPassed(const SDL_Rect &player_rect)
{
    for (auto &&w : walls_)
    {
        if (w.CheckPassed(player_rect))
            return true;
    }
    return false;
}

void WallHandler::Reset()
{
    walls_.clear();
    last_create_ = SDL_GetTicks();
}