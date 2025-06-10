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

#include <iostream>
#include "raylib.h"
#include <cstdint>

class Engine
{
private:
    //------------------------------------------------------------------------------------
    // Private members
    //------------------------------------------------------------------------------------
public:
    //------------------------------------------------------------------------------------
    // Private  methods
    //------------------------------------------------------------------------------------
    void initGame(const int16_t &width, const int16_t &height, const char *title);

public:
    //------------------------------------------------------------------------------------
    // Public methods - Mainly to be used in main.cpp
    //------------------------------------------------------------------------------------
    Engine();
    ~Engine();
};

#endif // ENGINE_H