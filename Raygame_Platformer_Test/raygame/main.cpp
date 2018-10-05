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
	playerObject.jumpHeight = 75;

	platform platformObject[8] = {
	{ 0.0f, 1050.0f, 1920.0f, 50.0f  },
	{ 0.0f, 850.0f, 1450.0f, 50.0f   },
	{ 1650.0f, 850.0f, 275.0f, 50.0f },
	{ 0.0f, 838.0f, 100.0f, 12.5f }, // Start of Moving Platforms
	{ 100.0f, 788.0f, 100.0f, 12.5f },
	{ 200.0f, 638.0f, 90.0f, 12.5f },
	{ 300.0f, 588.0f, 80.0f, 12.5f },
	{ 400.0f, 438.0f, 70.0f, 12.5f },
	};

	int platformMovmentCounter = 0;

	fanPlatform fanPlatformObject = { 1500.0f, 1038.0f, 125.0f, 12.5f };

									  // Left Point	       // Right Point		// Top Point
	obstacle obstacleObject[5] = { { { 500.0f, 1050.0f }, { 525.0f, 1050.0f }, { 512.5f, 1025.0f }, },
								   { { 600.0f, 1050.0f }, { 625.0f, 1050.0f }, { 612.5f, 1025.0f }, },
								   { { 700.0f, 1050.0f }, { 725.0f, 1050.0f }, { 712.5f, 1025.0f }, },
								   { { 500.0f, 850.0f  }, { 525.0f, 850.0f  }, { 512.5f, 825.0f  }, },
								   { { 450.0f, 850.0f  }, { 475.0f, 850.0f  }, { 462.5f, 825.0f  }, },
	};

	int obstacleMovmentCounter = 0;

	// This applies a Rectangle collider on the Obstacle Object 
	for (int i = 0; i < 5; i++) {
		obstacleObject[i].obstacleRectangleObject.x = obstacleObject[i].topPoint.x;
		obstacleObject[i].obstacleRectangleObject.y = obstacleObject[i].topPoint.y;
		//obstacleObject[i].obstacleRectangleObject.width = obstacleObject[i].leftPoint.x;
		obstacleObject[i].obstacleRectangleObject.height = obstacleObject[i].rightPoint.x - 500;
	}

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

		// Checks if Player is touching any platform
		for (size_t i = 0; i < 8; i++) {
			if (CheckCollisionRecs(playerObject.playerRectangleObject, platformObject[i].platformRectangleObject)) {
				playerObject.playerRectangleObject.y -= 2.5f;
			}
		}

		// Checks if Player is touching any Fan Platform
		for (size_t i = 0; i < 1; i++) {
			if (CheckCollisionRecs(playerObject.playerRectangleObject, fanPlatformObject.fanPlatformRectangleObject)) {
				playerObject.playerRectangleObject.y -= 250.0f;
			}
		}

		// This makes a Platform move up and down
		platformMovmentCounter++;

		for (size_t i = 3; i < 8; i++) {
			if (platformMovmentCounter < 222) {
				platformObject[i].platformRectangleObject.y -= 1.0f;
			}

			if (platformMovmentCounter >= 222) {
				platformObject[i].platformRectangleObject.y += 1.0f;
			}

			if (platformMovmentCounter == 443) {
				platformMovmentCounter = 0;
			}
		}

		// This makes a Obstacle move back and forth
		obstacleMovmentCounter++;

		for (size_t i = 3; i < 5; i++) {
			if (obstacleMovmentCounter < 19) {
				obstacleObject[i].leftPoint.x = obstacleObject[i].leftPoint.x - 5.0f;
				obstacleObject[i].rightPoint.x = obstacleObject[i].rightPoint.x - 5.0f;
				obstacleObject[i].topPoint.x = obstacleObject[i].topPoint.x - 5.0f;
			}

			if (obstacleMovmentCounter >= 19) {
				obstacleObject[i].leftPoint.x = obstacleObject[i].leftPoint.x + 5.0f;
				obstacleObject[i].rightPoint.x = obstacleObject[i].rightPoint.x + 5.0f;
				obstacleObject[i].topPoint.x = obstacleObject[i].topPoint.x + 5.0f;
			}

			if (obstacleMovmentCounter == 36) {
				obstacleMovmentCounter = 0;
			}
		}

		// Checks if Player is touching any Obstacle (Spikes in this instance)
		for (size_t i = 0; i < 5; i++) {
			if (CheckCollisionRecs(playerObject.playerRectangleObject, obstacleObject[i].obstacleRectangleObject)) {
				playerObject.playerRectangleObject.x = playerObject.startingPosition.x;
				playerObject.playerRectangleObject.y = playerObject.startingPosition.y;
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

		fanPlatformObject.draw();

		for (size_t i = 0; i < 5; i++) {
			obstacleObject[i].draw();
		}

		playerObject.draw();

		DrawText("Stand here!!!", 1500, 1000, 20, BLACK);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}