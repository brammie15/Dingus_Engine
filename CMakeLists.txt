cmake_minimum_required(VERSION 3.0)
project(raylib_template C CXX)

set(CMAKE_CXX_STANDARD 17)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)
add_subdirectory(libs/box2d)
include_directories(libs/box2d)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/util/RenderUtil.cpp
        src/util/RenderUtil.h
        src/earcut.hpp
        src/util/b2Vec2Helpers.cpp
        src/util/b2Vec2Helpers.h
        src/objects/box.cpp
        src/objects/box.h
        src/util/WorldUtil.cpp
        src/util/WorldUtil.h src/util/MathUtil.cpp src/util/MathUtil.h src/util/CONSTS.h src/util/MouseUtil.cpp src/util/MouseUtil.h)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_link_libraries(${PROJECT_NAME} PRIVATE box2d)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="relative-path-to-assets-in-the-game-package") # Set the asset path macro in release more
