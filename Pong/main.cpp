// PONG USING CPP AND RAYLIB
// STEPS
/*
    1. Create a window  --> DONE
    2. Create a ball and Paddle --> DONE
    3. Move Player paddle  --> DONE
    4. Collision Checking between Ball/Paddle and Borders  --> DONE
    5. Moven CPU paddle using AI  --> DONE
    6. Collision Checking between Ball and Paddle  -->
    7. Create a score


*/


#include "raylib.h"
#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "CPU.h"



int main() {
    const int ScreenWidth = 1200;
    const int ScreenHeight = 800;
    int FPS = 60;

    InitWindow(ScreenWidth, ScreenHeight, "Pong");
    SetTargetFPS(FPS);

    int WINNER = 0;
    int playerScore = 0;
    int cpuScore = 0;
    int start = 0;

    int speedX = 7;
    int speedY = 7;
    int radius = 20;
    Ball ball(ScreenWidth / 2, ScreenHeight / 2, speedX, speedY, radius);

    auto paddleWidth = 25;
    auto paddleHeight = 120;
    int paddleSpeed = 6;
    Paddle player(0, (ScreenHeight / 2 - paddleHeight / 2), paddleWidth, paddleHeight, paddleSpeed, WHITE);
    CPU cpu((ScreenWidth - paddleWidth), (ScreenHeight / 2 - paddleHeight / 2), paddleWidth, paddleHeight, paddleSpeed, WHITE, &ball);



    while (!WindowShouldClose()) {

        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            start = 1;
            WINNER = 0;
        }

        // Updating
        if (WINNER == 0 && start == 1) {
			ball.Update();
			player.Update();
			cpu.Update();
		}
        else if (WINNER == 1) {
            DrawText("Player Wins :)", ScreenWidth / 2 - 200, ScreenHeight / 2 - 200, 80, RED);
            start = 0;
			ball.x = ScreenWidth / 2;
			ball.y = ScreenHeight / 2;
			playerScore = 0;
			cpuScore = 0;
		}
        else if (WINNER == 2) {
            DrawText("CPU Wins! :(", ScreenWidth / 2 - 200, ScreenHeight / 2 - 200, 80, RED);
            start = 0;
            ball.x = ScreenWidth / 2;
            ball.y = ScreenHeight / 2;
            playerScore = 0;
            cpuScore = 0;
        }
        // Check for Collisions
        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, radius, Rectangle{ player.GetX(), player.GetY(), player.GetWidth(), player.GetHeight() })) {
            ball.speedX *= -1;
            playerScore += 1;
        }
        if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, radius, Rectangle{ cpu.GetX(), cpu.GetY(), cpu.GetWidth(), cpu.GetHeight() })) {
            ball.speedX *= -1;
            cpuScore += 1;
        }

        if (ball.x + radius >= GetScreenWidth()) {
            WINNER = 1;
        }
        else if (ball.x - radius <= 0) {
            WINNER = 2;
        }

        // Drawing
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("%0i", playerScore), ScreenWidth/4 - 20, 20, 80, RED);
        DrawText(TextFormat("%0i", cpuScore), 3 * ScreenWidth / 4 - 20, 20, 80, RED);
        ball.Draw();
        player.Draw();
        cpu.Draw();

        if (WINNER == 0) {
            DrawLine(ScreenWidth / 2, 0, ScreenWidth / 2, ScreenHeight, WHITE);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
