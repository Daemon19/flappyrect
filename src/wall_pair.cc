#include <SDL2/SDL.h>

#include "wall.h"
#include "wall_pair.h"

WallPair::WallPair(const Wall &top, const Wall &bottom)
    : top_(top), bottom_(bottom), out_of_frame_(false)
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