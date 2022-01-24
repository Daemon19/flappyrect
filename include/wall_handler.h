#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "wall.h"
#include "wall_pair.h"

class WallHandler
{
public:
    static const int kGapMin;
    static const int kGapMax;
    static const int kMinYOff;

private:
    int window_w_;
    int window_h_;
    Uint32 create_delay_;

    std::vector<WallPair> walls_;
    Uint32 last_create_;

public:
    WallHandler(const WallHandler &) = delete;
    WallHandler(int window_w, int window_h, Uint32 create_delay);

    void Update();
    void Draw(SDL_Renderer *renderer);
    bool CollideRect(const SDL_Rect &rect);
    void Reset();
};