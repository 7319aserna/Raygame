#include "Obstacle.h"
#include "raylib.h"

void obstacle::draw()
{
	DrawTriangleLines(leftPoint, rightPoint, topPoint, RED);
}