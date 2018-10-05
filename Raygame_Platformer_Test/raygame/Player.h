#pragma once

#include "raylib.h"

class player {
public:
	Rectangle playerRectangleObject;

	Vector2 startingPosition;

	int speed;
	int gravityEffect;
	int jumpHeight;

	void update(float deltaTime);
	void draw();
};