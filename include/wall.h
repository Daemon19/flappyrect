#pragma once

#include <SDL2/SDL.h>

#include "entity.h"

class Wall : public Entity
{
public:
    static const int kWallW;
    static const int kWallH;

    Wall(int x, int y);
    void Update();

    SDL_Rect rect() const { return rect_; }
    void set_pos(int x, int y);
};