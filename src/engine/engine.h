/********************************************************************************************
 * the-bartender.engine - A C++ game engine for the Bartender game.
 *
 * @author AbdielDev
 * @version 1.0.0
 * @LastModified 06/10/2025
 *
 * Thid gilr will take care of the engine's core functionalities.
 * DRAW, UPDATE, RENDER, INPUT, and more.
 *
 ********************************************************************************************/

#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include "definitions.h"
#include <iostream>
#include "raylib.h"
#include <cstdint>
#include "../../external/raygui/raygui.h"

//------------------------------------------------------------------------------------
// ENUM class for GameFPS in setting
//------------------------------------------------------------------------------------
enum class GameFPS : int
{
    //------------------------------------------------------------------------------------
    // OPTIONS for GameFPS
    //------------------------------------------------------------------------------------
    DEFAULT = 60,  // Default frames per second
    FPS_30 = 30,   // 30 frames per second
    FPS_60 = 60,   // 60 frames per second
    FPS_120 = 120, // 120 frames per second
    FPS_144 = 144, // 144 frames per second
    FPS_240 = 240  // 240 frames per second
};

class Engine
{
private:
    //------------------------------------------------------------------------------------
    // Private members
    //------------------------------------------------------------------------------------
    GameFPS desiredFPS = GameFPS::DEFAULT; // Desired frames per second
private:
    //-----------float-------------------------------------------------------------------------
    // Private  methods
    //------------------------------------------------------------------------------------
    void initGame(const std::int16_t &width, const std::int16_t &height, const char *title);
    GameFPS newDesiredFPS(const int &newFPS);
    void newDesiredResolution(const int &editResolution);
    void handleEvents();

public:
    //------------------------------------------------------------------------------------
    // Public methods - Mainly to be used in main.cpp
    //------------------------------------------------------------------------------------
    Engine();
    ~Engine();
};

#endif // ENGINE_H