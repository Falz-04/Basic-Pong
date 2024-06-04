#include "Paddle.h"
#include "raylib.h"

void Paddle::Draw() {
    DrawRectangleRec(rect, c);
}

void Paddle::Update() {
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        rect.y -= speed;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        rect.y += speed;
    }

    LimitMovement();

    
}

void Paddle::LimitMovement()
{
    if (rect.y <= 0) {
        rect.y = 0;
    }
    if (rect.y + rect.height >= GetScreenHeight()) {
        rect.y = GetScreenHeight() - rect.height;
    }
}
