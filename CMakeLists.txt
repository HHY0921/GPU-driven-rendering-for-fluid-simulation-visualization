cmake_minimum_required(VERSION 3.14)
project(FluidSimulation)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 設定 C++ 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 【關鍵】強制要求 Raylib 使用 OpenGL 4.3 編譯，以支援 Compute Shader
set(GRAPHICS "GRAPHICS_API_OPENGL_43" CACHE STRING "Require OpenGL 4.3" FORCE)

# 使用 FetchContent 自動下載 Raylib (完全不需手動抓取與設定路徑)
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        master # 或指定特定版本如 5.0
)
FetchContent_MakeAvailable(raylib)

# 設定你們自己的執行檔
add_executable(${PROJECT_NAME} src/main.cpp)

# 連結 Raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_SOURCE_DIR}/src)