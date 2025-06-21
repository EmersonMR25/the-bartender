
/********************************************************************************************
 * the-bartender.player
 *
 * @author AbdielDev
 * @version 1.0.0
 *
 * This file contains the Player class, which represents a player in the game.
 * It includes methods for player movement, interaction, and other player-related functionalities.
 *
 ********************************************************************************************/
#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
private:
    //------------------------------------------------------------------------------------
    // Private members
    //------------------------------------------------------------------------------------
    float positionX = 0.00f;         // Player's X position
    float positionY = 0.00f;         // Player's Y position
    float speed = 0.00f;             // Player's movement speed
    bool isMoving = false;           // Flag to check if the player is moving
    std::string playerName = "Kuro"; // Player's name
private:
    //------------------------------------------------------------------------------------
    // Private methods
    //------------------------------------------------------------------------------------

public:
    //------------------------------------------------------------------------------------
    // Public methods
    //------------------------------------------------------------------------------------
    Player(const float &startX, const float &startY, const float &playerSpeed);
    ~Player();

    void update(); // Update player state
    void render(); // Render player on screen

    // Getters
    float getPositionX() const;
    float getPositionY() const;
    bool isPlayerMoving() const;

    // Setters
    void setPosition(const float &x, const float &y);
    void setSpeed(const float &newSpeed);
};

#endif // PLAYER_H
