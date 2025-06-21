#include "player.h"
#include "raylib.h"
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
    //------------------------------------------------------------------------------------
    // This function is the bread and butter of the player rendering
    // It draws the player as a rectangle on the screen at the current position
    //
    // TO DO: Add a player sprite or texture instead of a rectangle
    //        Add an anumation for the player movement
    //------------------------------------------------------------------------------------
    DrawRectangle(static_cast<int>(positionX), static_cast<int>(positionY), 50, 50, BLUE);
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
