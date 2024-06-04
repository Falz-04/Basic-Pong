#pragma once
#include "raylib.h"

class Paddle {
public:
    Paddle(float x, float y, float width, float height, int speed, Color c)
        : rect{ x, y, width, height }, speed(speed), c(c)
    {};

    void Draw();
    virtual void Update(); // Made virtual to allow overriding in CPU class

    float GetX() const { return rect.x; }
    float GetY() const { return rect.y; }
    float GetWidth() const { return rect.width; }
    float GetHeight() const { return rect.height; }
protected:
    Rectangle rect;
    int speed;
    Color c;
    void LimitMovement();
};
