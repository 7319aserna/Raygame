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
#include "Platform.h"

#include <iostream>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------

	int screenWidth = 1920;
	int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "Platformer");

	SetTargetFPS(60);

	player playerObject;
	playerObject.startingPosition = { 0, 1030 };
	playerObject.playerRectangleObject.x = 0.0f;
	playerObject.playerRectangleObject.y = 0.0f;
	playerObject.playerRectangleObject.width = 25.0f;
	playerObject.playerRectangleObject.height = 25.0f;
	playerObject.gravityEffect = 1;
	playerObject.speed = 222.22f;
	playerObject.jumpHeight = 25;

	platform platformObject[3] = {
	{ 0.0f, 1050.0f, 154.0f, 30.0f },
	{ 0.0f, 1050.0f, 504.0f, 30.0f },
	{ 0.0f, 540.0f, 240.0f, 67.0f },
	};
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		playerObject.update(GetFrameTime());
		playerObject.playerRectangleObject.y += playerObject.gravityEffect;

		if (playerObject.playerRectangleObject.y > playerObject.startingPosition.y) {
			playerObject.playerRectangleObject.x = playerObject.startingPosition.x;
			playerObject.playerRectangleObject.y = playerObject.startingPosition.y;
		}

		for (size_t i = 0; i < 3; i++) {

			if (CheckCollisionRecs(playerObject.playerRectangleObject, platformObject->platformRectangleObject)) {
				playerObject.gravityEffect -= 1;
			}
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		for (size_t i = 0; i < 3; i++) {
			platformObject[i].draw();
		}

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