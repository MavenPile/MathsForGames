#include "raylib-cpp.hpp"
#include "SpriteObject.h"
#include "TankPlayer.h"

int main()
{
	//	Initialisation

	int screenWidth = 800;
	int screenHeight = 600;
	raylib::Color textColour = raylib::Color::LightGray();
	raylib::Window window(screenWidth, screenHeight, "Tank Game!");

	SetTargetFPS(60);

	SpriteObject turret;
	raylib::Texture2D turretSprite("res/Sprites/tankBlue_barrel1_outline.png");
	turret.m_sprite = &turretSprite;
	turret.SetLocalPosition(25, 0);

	GameObject turretBase;

	TankPlayer player(&turretBase);
	raylib::Texture2D tankSprite("res/Sprites/tankBody_blue_outline.png");
	player.m_sprite = &tankSprite;
	player.SetLocalPosition(screenWidth / 2, screenHeight / 2);


	turretBase.SetParent(&player);
	turret.SetParent(&turretBase);
	


	//	Main Game Loop

	while(!window.ShouldClose())
	{
		//	Update

		float deltaTime = window.GetFrameTime();
		player.Update(deltaTime);

		//	Draw

		BeginDrawing();
		{
			window.ClearBackground(RAYWHITE);

			player.Draw();
			turret.Draw();
		}
		EndDrawing();
	}

	return 0;
}