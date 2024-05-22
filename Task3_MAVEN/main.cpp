#include "raylib-cpp.hpp"
#include "SpriteObject.h"
#include "TankPlayer.h"
#include "TankTurret.h"
#include <iostream>
#include "Collider.h"
#include "BarrelObject.h"

int main()
{
	//	Initialisation

	int screenWidth = 1600;
	int screenHeight = 900;
	raylib::Color textColour = raylib::Color::LightGray();
	raylib::Window window(screenWidth, screenHeight, "Tank Game!");

	SetTargetFPS(60);

	//	ROOT

	GameObject root;
	GameObject::SetRoot(&root);
	std::vector<Collider*> colliders;	//	to store all colliders in the level

	//	MAP

	BarrelObject barrel(Math::Vector3(500,500,1));
	raylib::Texture2D barrelSprite("res/Sprites/barrelBlack_top.png");
	barrel.m_sprite = &barrelSprite;
	barrel.SetParent(GameObject::GetRoot());

	//	PLAYER

	TankPlayer player;
	player.SetParent(GameObject::GetRoot());
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
	bulletSpawn.SetLocalPosition(35,0);
	player.SetTurret(&bulletSpawn);

	//	Main Game Loop

	while(!window.ShouldClose())
	{
		//	Update

		float deltaTime = window.GetFrameTime();
		root.Update(deltaTime);

		//	COLLISION

		colliders.clear();
		root.GetAllChildColliders(colliders);
		std::cout << colliders.size() << std::endl;

		for (int i = 0; i < colliders.size(); i++)
		{
			for (int j = 0; j < colliders.size(); j++)
			{
				if (colliders[i]->m_owner != colliders[j]->m_owner)
				{
					colliders[i]->CollisionCheck(colliders[j]);
				}
			}
		}

		//	Draw

		BeginDrawing();
		{
			DrawText("Press W and S to move forward and backward.", 25, 25, 20, textColour);
			DrawText("Press A and D to turn left and right.", 25, 50, 20, textColour);
			DrawText("Press Q and E to rotate the turret.", 25, 75, 20, textColour);
			DrawText("Press C to fire a bullet.", 25, 100, 20, textColour);

			window.ClearBackground(RAYWHITE);
			window.DrawFPS();

			root.Draw();
		}
		EndDrawing();
	}

	return 0;
}