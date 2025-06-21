#include "player.h"
#include <iostream>

Player::Player(const float &startX, const float &startY, const float &playerSpeed)
{
    this->positionX = startX;
    this->positionY = startY;
    this->speed = playerSpeed;
    this->isMoving = false;    // Initialize isMoving to false
    this->playerName = "Kuro"; // Default player name
} // Player::Player

Player::~Player() {} // Player::~Player()

void Player::update()
{

} // Player::update()

void Player::render()
{

} // Player::render()

float Player::getPositionX() const
{
    return positionX;
} // Player::getPositionX()

float Player::getPositionY() const
{
    return positionY;
} // Player::getPositionY()

bool Player::isPlayerMoving() const
{
    return isMoving;
} // Player::isPlayerMoving()

void Player::setPosition(const float &x, const float &y)
{
    this->positionX = x;
    this->positionY = y;
} // Player::setPosition()

void Player::setSpeed(const float &newSpeed)
{
    this->speed = newSpeed;
} // Player::setSpeed()
