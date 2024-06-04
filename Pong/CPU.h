#pragma once
#include "Paddle.h"
#include "Ball.h"

class CPU : public Paddle {
public:
    CPU(float x, float y, float width, float height, int speed, Color c, Ball* ball)
        : Paddle(x, y, width, height, speed, c), ball(ball)
    {};

    void Update() override;

private:
    Ball* ball;
};
