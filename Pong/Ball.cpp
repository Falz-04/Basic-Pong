#include "Ball.h"

void Ball::Draw() {
    DrawCircle(x, y, radius, WHITE);
}

void Ball::Update() {
    x += speedX;
    y += speedY;

    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        speedY *= -1;
    }
    

}
