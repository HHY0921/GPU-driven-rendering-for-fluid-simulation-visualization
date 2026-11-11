#include "raylib.h"
#include "rlgl.h" // 讓你能呼叫 Raylib 封裝的底層 OpenGL 與 Compute Shader
#include <iostream>

int main() {
    // 建立 800x600 視窗
    InitWindow(800, 600, "GPU-Driven Fluid Simulation");
    SetTargetFPS(60);

    // 建立一個 3D 攝影機
    Camera3D camera = { 0 };
    camera.position = Vector3{ 10.0f, 10.0f, 10.0f };
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };        
    camera.fovy = 90.0f;                                
    camera.projection = CAMERA_PERSPECTIVE;             

    // 印出當前啟用的 OpenGL 版本 (專題除錯時非常重要)
    std::cout << "OpenGL Version: " << rlGetVersion() << std::endl;

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE); // 讓攝影機可以用滑鼠鍵盤漫遊

        BeginDrawing();
        ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                // 畫一個網格當作地板
                DrawGrid(10, 1.0f);
                
                // 畫一顆紅色的球，這就是你們未來的「障礙物」
                DrawSphere(Vector3{0.0f, 1.0f, 0.0f}, 1.0f, RED);
            EndMode3D();

            DrawFPS(10, 10);
            DrawText("Environment Setup Successful!", 10, 40, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}


