#include "raylib-cpp.hpp"
#include "SpriteObject.h"
#include "TankPlayer.h"
#include "TankTurret.h"
#include <iostream>

int main()
{
	//	Initialisation

	GameObject root;
	GameObject::SetRoot(&root);

	int screenWidth = 1600;
	int screenHeight = 900;
	raylib::Color textColour = raylib::Color::LightGray();
	raylib::Window window(screenWidth, screenHeight, "Tank Game!");

	SetTargetFPS(60);

	//	MAP

	SpriteObject barrel;
	raylib::Texture2D barrelSprite("res/Sprites/barrelBlack_top.png");
	barrel.m_sprite = &barrelSprite;
	barrel.SetParent(&root);
	barrel.SetLocalPosition(500, 500);


	//SpriteObject tile;
	//raylib::Texture2D tileSprite("res/Sprites/tileSand1.png");
	//tile.m_sprite = &tileSprite;
	//tile.SetLocalPosition(50, 50);
	//tile.SetParent(&root);

	//	PLAYER

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
	raylib::Texture2D bulletSprite("res/Sprites/bulletBlue1_outline.png");
	bulletSpawn.SetBulletSprite(&bulletSprite);
	bulletSpawn.SetParent(&turret);
	bulletSpawn.SetLocalPosition(25,0);
	player.SetTurret(&bulletSpawn);

	//	Main Game Loop

	while(!window.ShouldClose())
	{
		//	Update

		float deltaTime = window.GetFrameTime();
		root.Update(deltaTime);

		//	Draw

		BeginDrawing();
		{
			DrawText("Press W and S to move forward and backward.", 25, 25, 20, textColour);
			DrawText("Press A and D to turn left and right.", 25, 50, 20, textColour);
			DrawText("Press Q and E to rotate the turret.", 25, 75, 20, textColour);
			DrawText("Press C to fire a bullet.", 25, 100, 20, textColour);

			window.ClearBackground(RAYWHITE);

			root.Draw();
		}
		EndDrawing();
	}

	return 0;
}