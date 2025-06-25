/********************************************************************************************
 * the-bartender.engine - A C++ game engine for the Bartender game.
 *
 * @author AbdielDev
 * @version 1.0.0
 *
 * Thid gilr will take care of the engine's core functionalities.
 * DRAW, UPDATE, RENDER, INPUT, and more.
 *
 ********************************************************************************************/

#include "engine.h"
#include "definitions.h"
#include "../player/player.h"
#include <iostream>
#include "raygui.h"
#include "raylib.h"

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

    delete player; // Clean up the player object if it exists
    player = nullptr;
}

void Engine::initGame(const int16_t &width, const int16_t &height, const char *title)
{

    InitWindow(width, height, title);
    SetTargetFPS(static_cast<int>(desiredFPS)); // Set the game to run at 60 frames per second

    //------------------------------------------------------------------------------------
    // Initialize the game camera
    //------------------------------------------------------------------------------------
    Camera2D camera = {0};

    while (!WindowShouldClose()) // Main game loop
    {
        //------------------------------------------------------------------------------------
        // Initialize the player object if it hasn't been created yet
        //------------------------------------------------------------------------------------
        if (player == nullptr)
        {
            player = new Player(500.0f, 500.0f, 5.0f);
        }

        //------------------------------------------------------------------------------------
        // Handle events and input before drawing
        //------------------------------------------------------------------------------------
        handleEvents();
        //------------------------------------------------------------------------------------
        // Update all entities and game logic here
        //------------------------------------------------------------------------------------
        update();
        //------------------------------------------------------------------------------------
        // Draw the game UI and elements
        //------------------------------------------------------------------------------------
        render();
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
} // Engine::newDesiredResolution()

void Engine::handleEvents()
{
} // Engine::handleEvents()

void Engine::update()
{
    // TO DO
} // Engine::update()

void Engine::render()
{
    //------------------------------------------------------------------------------------
    // Render the player and other game elements
    //------------------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (GuiDropdownBox((Rectangle){10, 60, 120, 20}, "640x480;800x600;1024x768;1280x720;1920x1080;2560x1440;3840x2160", &editResolution, resolutionEditMode))
    {
        newDesiredResolution(editResolution);
        resolutionEditMode = !resolutionEditMode;
    }

    if (GuiDropdownBox((Rectangle){10, 30, 120, 20}, "30;60;120;144;240", &editFPS, fpsEditMode))
    {
        SetTargetFPS(static_cast<int>(newDesiredFPS(editFPS))); // Update the target FPS based on the dropdown selection
        fpsEditMode = !fpsEditMode;
    }

    //------------------------------------------------------------------------------------
    // Render the player object. Check if the player pointer is not null before rendering.
    //------------------------------------------------------------------------------------
    if (player)
    {
        player->render();
    }

    DrawFPS(10, 10); // Draw the FPS counter in the top-left corner
    EndDrawing();
} // Engine::render()