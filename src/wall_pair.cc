#include <SDL2/SDL.h>

#include "wall.h"
#include "wall_pair.h"

WallPair::WallPair(const Wall &top, const Wall &bottom)
    : top_(top), bottom_(bottom), out_of_frame_(false), passed_by_player_(false)
{
}

void WallPair::Update()
{
    top_.Update();
    bottom_.Update();

    if (top_.rect().x + top_.rect().w < 0)
        out_of_frame_ = true;
}

void WallPair::Draw(SDL_Renderer *renderer)
{
    top_.Draw(renderer);
    bottom_.Draw(renderer);
}

bool WallPair::CollideRect(const SDL_Rect &rect)
{
    auto CollideRect = [&](const SDL_Rect &other)
    {
        return (rect.x <= other.x + other.w && rect.x + rect.w >= other.x &&
                rect.y <= other.y + other.h && rect.y + rect.h >= other.y);
    };

    return CollideRect(top_.rect()) || CollideRect(bottom_.rect());
}

bool WallPair::CheckPassed(const SDL_Rect &player_rect)
{
    if (!passed_by_player_ && player_rect.x > top_.rect().x + top_.rect().w)
    {
        passed_by_player_ = true;
        return true;
    }
    return false;
}