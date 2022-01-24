#include <SDL2/SDL.h>

#include "player.h"

const float Player::kGravity = 0.8;
const float Player::kJumpVel = -16;

Player::Player(const SDL_Rect &rect)
    : rect_(rect), yvel_(0)
{
}

void Player::Jump()
{
    yvel_ = kJumpVel;
}

void Player::Update()
{
    yvel_ += kGravity;
    rect_.y += yvel_;
}

void Player::Draw(SDL_Renderer *renderer)
{
    SDL_RenderFillRect(renderer, &rect_);
}
