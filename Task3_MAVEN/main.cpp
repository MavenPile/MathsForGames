#include "raylib-cpp.hpp"

int main()
{
	//	Initialisation

	int screenWidth = 800;
	int screenHeight = 600;
	raylib::Color textColour = raylib::Color::LightGray();
	raylib::Window window(screenWidth, screenHeight, "This is the window title!");

	SetTargetFPS(60);

	//	Main Game Loop

	while (!window.ShouldClose())
	{
		//	Update
		//	--------------------
		//	Update your variables here
		//	-------------------

		//	Draw

		BeginDrawing();

		{
			window.ClearBackground(RAYWHITE);
			textColour.DrawText("This is the window!", 190, 200, 20);
		}

		EndDrawing();
	}

	return 0;
}