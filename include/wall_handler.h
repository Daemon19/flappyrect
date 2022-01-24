#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "wall.h"

class WallPair
{
private:
    Wall top_;
    Wall bottom_;
    bool out_of_frame_;

public:
    // \param x left side of wall pair
    // \param y bottom left of top wall
    WallPair(const Wall &top, const Wall &bottom);
    void Update();
    void Draw(SDL_Renderer *renderer);

    bool out_of_frame() const { return out_of_frame_; }
};

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
};