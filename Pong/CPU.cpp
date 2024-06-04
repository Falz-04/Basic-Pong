#include "CPU.h"
#include "raylib.h"

void CPU::Update() {

	if (rect.y + (rect.height / 2) > ball->y) {
		rect.y -= speed;
	}
	if (rect.y + (rect.height / 2) <= ball->y) {
		rect.y += speed;
	}

	LimitMovement();
}
