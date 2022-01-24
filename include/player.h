#pragma once

#include <SDL2/SDL.h>

#include "entity.h"

class Player : public Entity
{
public:
    static const float kGravity;
    static const float kJumpVel;

private:
    float yvel_;

public:
    Player(const SDL_Rect &rect);
    void Jump();
    void Update();
};