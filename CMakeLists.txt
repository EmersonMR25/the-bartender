cmake_minimum_required(VERSION 3.15)
project(the-bartender LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include(FetchContent)

# Raylib setup
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
)
set(FETCHCONTENT_QUIET OFF)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(BUILD_GUITHREADS OFF CACHE BOOL "" FORCE)
set(BUILD_STANDALONE ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

# Raygui (header-only)
include_directories(external/raygui)

# Ensure IDEs detect Raylib headers
include_directories(${raylib_SOURCE_DIR}/src)

# Collect sources
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp src/*.h)

# Build executable
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} raylib)

# macOS frameworks
if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
endif()

# Copy assets to bin/assets after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/assets
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)