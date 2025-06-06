cmake_minimum_required(VERSION 3.11)
project(the-bartender LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile_commands.json for IDEs like VS Code
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configure output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build/bin)

# Include external libraries for raygui
include_directories(external/raygui)

# --- External Dependencies ---
# Fetch and configure Raylib
include(FetchContent)
FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
)

FetchContent_GetProperties(raylib)
if (NOT raylib_POPULATED)
    FetchContent_MakeAvailable(raylib)
    # Prevent Raylib from building its examples
    set(BUILD_EXAMPLES OFF CACHE BOOL "Do not build Raylib examples" FORCE)
endif()

# Ensure IDEs detect Raylib headers
include_directories(${raylib_SOURCE_DIR}/src)

# --- Project Configuration ---
# Collect all source files
file(GLOB_RECURSE SRC_FILES
    src/*.cpp
    src/*.h
)

# Create the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link Raylib to your executable
target_link_libraries(${PROJECT_NAME} raylib)

# MacOS specific settings for Raylib
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
endif()

# --- Post-Build Steps ---
# Ensure the assets folder is copied into the build directory's bin folder
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
    COMMENT "Copying assets to the build directory"
)