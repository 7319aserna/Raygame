#pragma once

#include "raylib.h"

class player {
public:
	Rectangle playerRectangleObject;

	Vector2 startingPosition;

	int gravityEffect;
	int jumpHeight;
	int speed;

	void update(float deltaTime);
	void draw();
};