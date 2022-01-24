#include <SDL2/SDL.h>

#include "player.h"

const float Player::kGravity = 0.8;
const float Player::kJumpVel = -14;
const int Player::kSize = 60;

Player::Player(int x, int y)
    : Entity({x, y, kSize, kSize}), start_x_(x), start_y_(y), yvel_(0)
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

void Player::Reset()
{
    rect_.x = start_x_;
    rect_.y = start_y_;
    Jump();
}