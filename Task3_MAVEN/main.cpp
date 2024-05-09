#include "raylib-cpp.hpp"
#include "SpriteObject.h"
#include "TankPlayer.h"
#include "TankTurret.h"

int main()
{
	//	Initialisation

	int screenWidth = 800;
	int screenHeight = 600;
	raylib::Color textColour = raylib::Color::LightGray();
	raylib::Window window(screenWidth, screenHeight, "Tank Game!");

	SetTargetFPS(60);

	GameObject root;
	GameObject::SetRoot(&root);

	TankPlayer player;
	player.SetParent(&root);
	raylib::Texture2D tankSprite("res/Sprites/tankBody_blue_outline.png");
	player.m_sprite = &tankSprite;
	player.SetLocalPosition(screenWidth / 2, screenHeight / 2);

	GameObject turretBase;
	turretBase.SetParent(&player);
	player.SetTurretPivot(&turretBase);

	SpriteObject turret;
	raylib::Texture2D turretSprite("res/Sprites/tankBlue_barrel1_outline.png");
	turret.m_sprite = &turretSprite;
	turret.SetParent(&turretBase);
	turret.SetLocalPosition(25, 0);

	TankTurret bulletSpawn;
	bulletSpawn.SetParent(&turret);
	bulletSpawn.SetLocalPosition(25,0);

	//	Main Game Loop

	while(!window.ShouldClose())
	{
		//	Update

		float deltaTime = window.GetFrameTime();
		root.Update(deltaTime);

		//	Draw

		BeginDrawing();
		{
			window.ClearBackground(RAYWHITE);

			root.Draw();
		}
		EndDrawing();
	}

	return 0;
}