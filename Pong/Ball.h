#pragma once
#include "raylib.h"

class Ball {
public:
    Ball(float x, float y, int speedX, int speedY, int radius)
        : x(x), y(y), speedX(speedX), speedY(speedY), radius(radius)
    {};

    void Draw();
    void Update();

    float x, y; // Made public to be accessible by CPU
    int speedX, speedY;
private:
    int radius;
};
