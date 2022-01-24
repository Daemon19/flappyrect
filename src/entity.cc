#include <SDL2/SDL.h>

#include "entity.h"

const float Entity::kXVel = -5;

Entity::Entity(const SDL_Rect &rect)
    : rect_(rect)
{
}

void Entity::Draw(SDL_Renderer *renderer)
{
    SDL_RenderFillRect(renderer, &rect_);
}