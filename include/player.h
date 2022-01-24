#pragma once

#include <SDL2/SDL.h>

#include "entity.h"

class Player : public Entity
{
public:
    static const float kGravity;
    static const float kJumpVel;
    static const int kSize;

private:
    const int start_x_;
    const int start_y_;
    float yvel_;

public:
    Player(int x, int y);
    void Jump();
    void Update();
    void Reset();
};