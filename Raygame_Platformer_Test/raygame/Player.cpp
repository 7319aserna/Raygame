#include "Player.h"
#include "raylib.h"

void player::update(float deltaTime)
{
	if (IsKeyDown(KEY_A)) {
		playerRectangleObject.x -= speed * deltaTime;
	}
	if (IsKeyDown(KEY_D)) {
		playerRectangleObject.x += speed * deltaTime;
	}
	if (IsKeyPressed(KEY_SPACE)) {
		playerRectangleObject.y -= jumpHeight;
	}
	if (IsKeyDown(KEY_SPACE) && IsKeyDown(KEY_D)) {
		playerRectangleObject.x += 10.0f;
	}
	if (IsKeyDown(KEY_SPACE) && IsKeyDown(KEY_A)) {
		playerRectangleObject.x -= 10.0f;
	}
	if (IsKeyReleased(KEY_SPACE)) {
		playerRectangleObject.y += jumpHeight;
	}
}

void player::draw()
{
	DrawRectangle(playerRectangleObject.x, playerRectangleObject.y, playerRectangleObject.width, playerRectangleObject.height, SKYBLUE);
}