#include <SDL2/SDL.h>

#include "player.h"

const float Player::kGravity = 0.8;
const float Player::kJumpVel = -14;

Player::Player(const SDL_Rect &rect, const float yvel)
    : Entity(rect), yvel_(yvel)
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