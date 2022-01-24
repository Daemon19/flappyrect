#pragma once

#include <SDL2/SDL.h>

class Player
{
public:
    static const float kGravity;
    static const float kJumpVel;

private:
    SDL_Rect rect_;
    float yvel_;

public:
    Player(const SDL_Rect &rect);
    void Jump();
    void Update();
    void Draw(SDL_Renderer *renderer);
};