#include "raylib-cpp.hpp"
#include "Colour.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"
#include "SpriteObject.h"
#include "GameObject.h"

#include <chrono>

//using namespace raylib::

int main()
{
	//	Initialisation

	int screenWidth = 800;
	int screenHeight = 600;
	Color textColour = raylib::Color::LightGray();
	raylib::Window window(screenWidth, screenHeight, "This is the window title!");

	SetTargetFPS(60);

	raylib::Texture2D tankSprite("res/tankBody_blue_outline.png");

	SpriteObject Player;

	Player.m_sprite = &tankSprite;

	Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);

	//	Main Game Loop

	while(!window.ShouldClose())
	{
		//	Update

		float deltaTime = window.GetFrameTime();
		Player.Update(deltaTime);

		//	Draw

		BeginDrawing();
		{
			window.ClearBackground(RAYWHITE);

			textColour.DrawText("This is the window!", 190, 200, 20);

			Player.Draw;
		}
		EndDrawing();
	}

	return 0;
}