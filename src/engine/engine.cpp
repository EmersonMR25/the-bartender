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
#define RAYGUI_IMPLEMENTATION
#include "../../external/raygui/raygui.h"

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
    SetTargetFPS(static_cast<int>(desiredFPS)); // Set the game to run at 60 frames per second

    while (!WindowShouldClose()) // Main game loop
    {
        // Update and draw the game here
        // This is where the game logic will be implemented
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Welcome to The Bartender!", 190, 200, 20, LIGHTGRAY);

        GuiSliderBar((Rectangle){600, 40, 120, 20}, "FPS", TextFormat("%.2f", desiredFPS), &desiredFPS, MIN_FPS, MAX_FPS); // Slider for FPS control
        SetTargetFPS(static_cast<int>(desiredFPS));                                                                        // Update the target FPS based on the slider value
        DrawFPS(10, 10);                                                                                                   // Draw the FPS counter in the top-left corner
        EndDrawing();
    }

    CloseWindow(); // Close the window and clean up resources
} // Engine::initGame()