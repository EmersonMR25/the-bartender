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

#include "engine.h"
Engine::Engine()
{
    //------------------------------------------------------------------------------------
    // Public default consuntructor
    // It initializes the engine and sets up the window
    //------------------------------------------------------------------------------------
    initGame(GetScreenHeight(), GetScreenWidth(), "The Bartender");

} // Engine::Engines()

Engine::~Engine()
{
    // Destructor implementation
    // do nothing yet
}

void Engine::initGame(const int16_t &width, const int16_t &height, const char *title)
{
    InitWindow(width, height, title);
    SetTargetFPS(60); // Set the game to run at 60 frames per second

    while (!WindowShouldClose()) // Main game loop
    {
        // Update and draw the game here
        // This is where the game logic will be implemented
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Welcome to The Bartender!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow(); // Close the window and clean up resources
} // Engine::initGame()