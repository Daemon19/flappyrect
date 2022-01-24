#include <SDL2/SDL.h>

#include "entity.h"
#include "wall.h"

const int Wall::kWallW = 80;
const int Wall::kWallH = 10000;

Wall::Wall(int x, int y)
    : Entity({x, y, kWallW, kWallH})
{
}

void Wall::Update()
{
    rect_.x += kXVel;
}

void Wall::set_pos(int x, int y)
{
    rect_.x = x;
    rect_.y = y;
}