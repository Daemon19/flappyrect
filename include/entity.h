#pragma once

#include <SDL2/SDL.h>

class Entity
{
public:
    static const float kXVel;

protected:
    SDL_Rect rect_;

public:
    Entity(const SDL_Rect &rect);
    virtual ~Entity() {}
    virtual void Update() = 0;
    virtual void Draw(SDL_Renderer *renderer) const;
};