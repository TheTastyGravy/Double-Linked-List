#include "raylib.h"




int main()
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HIGHT = 450;

	InitWindow(SCREEN_WIDTH, SCREEN_HIGHT, "Double-Linked List demo");
	SetTargetFPS(60);

	// Game loop
	while (!WindowShouldClose())
	{


		// Draw
		BeginDrawing();

		ClearBackground(RAYWHITE);


		EndDrawing();
	}



	CloseWindow();
	return 0;
}