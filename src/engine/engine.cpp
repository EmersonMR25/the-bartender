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

void Engine::initGame(const std::int16_t &width, const std::int16_t &height, const char *title)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height, title);
    SetTargetFPS(static_cast<int>(desiredFPS)); // Set the game to run at 60 frames per second

    bool fpsEditMode = false;        // Flag to check if FPS edit mode is active
    int editFPS = 1;                 // Variable to hold the FPS value for editing, will be 60 by default
    bool resolutionEditMode = false; // Flag to check if resolution edit mode is active
    int editResolution = 0;          // Variable to hold the resolution value for editing

    while (!WindowShouldClose()) // Main game loop
    {
        // Update and draw the game here
        // This is where the game logic will be implemented
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (GuiDropdownBox((Rectangle){10, 30, 120, 20}, "30;60;120;144;240", &editFPS, fpsEditMode))
        {
            SetTargetFPS(static_cast<int>(newDesiredFPS(editFPS))); // Update the target FPS based on the dropdown selection
            fpsEditMode = !fpsEditMode;
        }

        if (GuiDropdownBox((Rectangle){10, 60, 120, 20}, "640x480;800x600;1024x768;1280x720;1920x1080;2560x1440;3840x2160", &editResolution, resolutionEditMode))
        {
            newDesiredResolution(editResolution);
            resolutionEditMode = !resolutionEditMode;
        }

        DrawFPS(10, 10); // Draw the FPS counter in the top-left corner
        EndDrawing();
    }

    CloseWindow(); // Close the window and clean up resources
} // Engine::initGame()

GameFPS Engine::newDesiredFPS(const int &newFPS)
{
    switch (newFPS)
    {
    case 0:
        desiredFPS = GameFPS::FPS_30;
        break;
    case 1:
        desiredFPS = GameFPS::FPS_60;
        break;
    case 2:
        desiredFPS = GameFPS::FPS_120;
        break;
    case 3:
        desiredFPS = GameFPS::FPS_144;
        break;
    case 4:
        desiredFPS = GameFPS::FPS_240;
        break;
    default:
        desiredFPS = GameFPS::DEFAULT; // Default to 60 FPS if no valid selection
    }
    return desiredFPS; // Return the updated desired FPS
} // Engine::newDesiredFPS()

void Engine::newDesiredResolution(const int &editResolution)
{
    switch (editResolution)
    {
    case 0:
        SetWindowSize(640, 480);
        break;
    case 1:
        SetWindowSize(800, 600);
        break;
    case 2:
        SetWindowSize(1024, 768);
        break;
    case 3:
        SetWindowSize(1280, 720);
        break;
    case 4:
        SetWindowSize(1920, 1080);
        break;
    case 5:
        SetWindowSize(2560, 1440);
        break;
    case 6:
        SetWindowSize(3840, 2160);
        break;
    }
}