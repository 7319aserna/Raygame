#include "Platform.h"
#include "raylib.h"

void platform::draw()
{
	DrawRectangle(platformRectangleObject.x, platformRectangleObject.y, platformRectangleObject.width, platformRectangleObject.height, ORANGE);
}
