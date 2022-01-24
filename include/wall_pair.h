#pragma once

#include <SDL2/SDL.h>

#include "wall.h"

class WallPair
{
private:
    Wall top_;
    Wall bottom_;
    bool out_of_frame_;

public:
    WallPair(const Wall &top, const Wall &bottom);
    void Update();
    void Draw(SDL_Renderer *renderer);

    bool out_of_frame() const { return out_of_frame_; }
};