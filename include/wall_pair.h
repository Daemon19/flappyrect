#pragma once

#include <SDL2/SDL.h>

#include "wall.h"

class WallPair
{
private:
    Wall top_;
    Wall bottom_;
    bool out_of_frame_;
    bool passed_by_player_;

public:
    WallPair(const Wall &top, const Wall &bottom);

    void Update();
    void Draw(SDL_Renderer *renderer);
    bool CollideRect(const SDL_Rect &rect);
    bool CheckPassed(const SDL_Rect &player_rect);

    bool out_of_frame() const { return out_of_frame_; }
    bool passed_by_player() const { return passed_by_player_; }
};