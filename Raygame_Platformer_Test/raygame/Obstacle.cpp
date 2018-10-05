#include "Obstacle.h"
#include "raylib.h"

void obstacle::draw()
{
	Vector2 v1 = leftPoint;
	Vector2 v2 = rightPoint;
	Vector2 v3 = topPoint;

	DrawTriangle(v1, v2, v3, RED);
	//DrawTriangleLines(leftPoint, rightPoint, topPoint, RED);
}