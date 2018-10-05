#pragma once

#include "raylib.h"

class obstacle {
public:
	Vector2 leftPoint;
	Vector2 rightPoint;
	Vector2 topPoint;

	//Rectangle obstacleObject;

	void draw();
};