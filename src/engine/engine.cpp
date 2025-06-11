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
    SetTargetFPS(static_cast<int>(desiredFPS)); // Set the game to run at 60 frames per second

    bool fpsEditMode = false; // Flag to check if FPS edit mode is active
    int editFPS = 1;          // Variable to hold the FPS value for editing

    while (!WindowShouldClose()) // Main game loop
    {
        // Update and draw the game here
        // This is where the game logic will be implemented
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Welcome to The Bartender!", 190, 200, 20, LIGHTGRAY);

        if (GuiDropdownBox((Rectangle){10, 30, 120, 20}, "30;60;120;144;240", &editFPS, fpsEditMode))
        {
            fpsEditMode = !fpsEditMode; // Dropdown for FPS selection
        }
        std::cout << "FPS EDIT MODE: " << editFPS << std::endl;
        switch (editFPS)
        {
        case 0: // 30 FPS
            desiredFPS = GameFPS::FPS_30;
            break;
        case 1: // 60 FPS
            desiredFPS = GameFPS::FPS_60;
            break;
        case 2: // 120 FPS
            desiredFPS = GameFPS::FPS_120;
            break;
        case 3: // 144 FPS
            desiredFPS = GameFPS::FPS_144;
            break;
        case 4: // 240 FPS
            desiredFPS = GameFPS::FPS_240;
            break;
        default:
            desiredFPS = GameFPS::DEFAULT; // Default to 60 FPS if no valid selection
        }

        SetTargetFPS(static_cast<int>(desiredFPS)); // Update the target FPS based on the slider value

        DrawFPS(10, 10); // Draw the FPS counter in the top-left corner
        EndDrawing();
    }

    CloseWindow(); // Close the window and clean up resources
} // Engine::initGame()