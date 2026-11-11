cmake_minimum_required(VERSION 3.14)
project(FluidSimulation)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FORCE Raylib to use OpenGL 4.3 for Compute Shader
# default Raylib use OpenGL 3
set(GRAPHICS "GRAPHICS_API_OPENGL_43" CACHE STRING "Require OpenGL 4.3" FORCE)

# FetchContent Raylib (完全不需手動抓取與設定路徑)
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        master
)
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME} src/main.cpp)

# link Raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_SOURCE_DIR}/src)