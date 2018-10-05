/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#include "Player.h"
#include "Obstacle.h"
#include "Platform.h"

#include <iostream>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------

	float screenWidth = 1920.0f;
	float screenHeight = 1080.0f;

	InitWindow(screenWidth, screenHeight, "Platformer");

	SetTargetFPS(60);

	player playerObject;
	playerObject.startingPosition = { 0, 1030 };
	playerObject.playerRectangleObject.x = playerObject.startingPosition.x;
	playerObject.playerRectangleObject.y = playerObject.startingPosition.y;
	playerObject.playerRectangleObject.width = 25.0f;
	playerObject.playerRectangleObject.height = 25.0f;
	playerObject.gravityEffect = 1;
	playerObject.speed = 222.22f;
	playerObject.jumpHeight = 50;

	platform platformObject[8] = {
	{ 0.0f, 1050.0f, 250.0f, 50.0f },
	{ 250.0f, 1050.0f, 250.0f, 50.0f },
	{ 500.0f, 1050.0f, 250.0f, 50.0f },
	{ 750.0f, 1050.0f, 250.0f, 50.0f },
	{ 1000.0f, 1050.0f, 250.0f, 50.0f },
	{ 1250.0f, 1050.0f, 250.0f, 50.0f },
	{ 1500.0f, 1050.0f, 250.0f, 50.0f },
	{ 1750.0f, 1050.0f, 250.0f, 50.0f },
	};

	obstacle obstacleObject;
						// Left Point	// Right Point		   // Top Point
	obstacleObject = { { 0.0f, 0.0f }, { screenWidth, 0.0f }, { 0.0f, screenHeight }, };

	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		playerObject.update(GetFrameTime());
		playerObject.playerRectangleObject.y += playerObject.gravityEffect;

		if (playerObject.playerRectangleObject.x > screenWidth) {
			playerObject.playerRectangleObject.x = playerObject.startingPosition.x;
			playerObject.playerRectangleObject.y = playerObject.startingPosition.y;
		}

		if (!playerObject.playerRectangleObject.x > screenWidth) {
			playerObject.playerRectangleObject.x = playerObject.startingPosition.x;
			playerObject.playerRectangleObject.y = playerObject.startingPosition.y;
		}

		if (playerObject.playerRectangleObject.y > playerObject.startingPosition.y + 5.0f) {
			playerObject.playerRectangleObject.x = playerObject.startingPosition.x;
			playerObject.playerRectangleObject.y = playerObject.startingPosition.y;
		}

		for (size_t i = 0; i < 8; i++) {
			if (CheckCollisionRecs(playerObject.playerRectangleObject, platformObject[i].platformRectangleObject)) {
				playerObject.playerRectangleObject.y -= 2.5f;
			}
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		for (size_t i = 0; i < 8; i++) {
			platformObject[i].draw();
		}

		obstacleObject.draw();

		playerObject.draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}