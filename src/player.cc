#include <SDL2/SDL.h>

#include "player.h"

const float Player::kGravity = 0.8;
const float Player::kJumpVel = -16;

Player::Player(const SDL_Rect &rect)
    : Entity(rect), yvel_(0)
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