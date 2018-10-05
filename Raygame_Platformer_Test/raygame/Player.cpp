#include "Player.h"
#include "raylib.h"

void player::update(float deltaTime)
{
	if (IsKeyDown(KEY_S)) {
		playerRectangleObject.y += speed * deltaTime;
	}
	if (IsKeyDown(KEY_A)) {
		playerRectangleObject.x -= speed * deltaTime;
	}
	if (IsKeyDown(KEY_D)) {
		playerRectangleObject.x += speed * deltaTime;
	}
	if (IsKeyPressed(KEY_SPACE)) {
		playerRectangleObject.y -= jumpHeight;
	}
	if (IsKeyReleased(KEY_SPACE)) {
		playerRectangleObject.y += jumpHeight;
	}
}

void player::draw()
{
	DrawRectangle(playerRectangleObject.x, playerRectangleObject.y, playerRectangleObject.width, playerRectangleObject.height, SKYBLUE);
}