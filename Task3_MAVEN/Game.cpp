#include "Game.h"
#include "GameObject.h"
#include "Collider.h"
#include "TankPlayer.h"
#include "SpriteObject.h"
#include "BarrelObject.h"

Game::Game(int winWidth, int winHeight)
{
	//	WINDOW
	
	m_deltaTime = 0.f;
	m_screenWidth = winWidth;
	m_screenHeight = winHeight;
	m_window = raylib::Window(m_screenWidth, m_screenHeight, "Tank Game!");

	//	SPRITES

	//m_tankSprite = raylib::Texture2D("res/Sprites/tankBody_blue_outline.png");
	//m_turretSprite = raylib::Texture2D("res/Sprites/tankBlue_barrel1_outline.png");
	//m_barrelSprite = raylib::Texture2D("res/Sprites/barrelBlack_top.png");

	//	WORLD

	GameObject::SetRoot(m_root);	//	world root and ancestor of all game objects
	
	//BarrelObject m_barrel;
	//m_barrel.Construct(500, 500);
	//m_barrel.SetParent(m_root);
	//raylib::Texture2D barrelSprite("res/Sprites/barrelBlack_top.png");
	//m_barrel.m_sprite = &barrelSprite;

		//	try to create a vector to contain barrels, and work with that
		//	can we procedurally generate a world of tiles and barrels?

	//	PLAYER

	m_player->SetParent(m_root);
	raylib::Texture2D tankSprite("res/Sprites/tankBody_blue_outline.png");
	m_player->m_sprite = &tankSprite;
	m_player->SetLocalPosition(m_screenWidth / 2, m_screenHeight / 2);

	m_pivot->SetParent(m_player);
	m_player->SetTurretPivot(m_pivot);

	m_turret->SetParent(m_pivot);
	raylib::Texture2D turretSprite("res/Sprites/tankBlue_barrel1_outline.png");
	m_turret->m_sprite = &turretSprite;
	m_turret->SetLocalPosition(25, 0);

}

Game::~Game() {}

void Game::Run()
{
	while (!m_window.ShouldClose())
	{
		//	UPDATE

		m_deltaTime = m_window.GetFrameTime();	//	gets deltatime
		m_root->Update(m_deltaTime);	//	updates the whole level

		//	COLLISION

		m_colliders.clear();	//	clears our collider storage
		m_root->GetAllChildColliders(m_colliders);	//	fills m_colliders with pointers to the colliders of m_root and all it's children

		for (int i = 0; i < m_colliders.size(); i++)
		{
			for (int j = 0; j < m_colliders.size(); j++)
			{
				if (m_colliders[i]->m_owner != m_colliders[j]->m_owner)
				{
					m_colliders[i]->CollisionCheck(m_colliders[j]);
				}
			}
		}	//	TRY AND OPTIMISE THIS

		//	DRAW

		BeginDrawing();
		{
			//	BACKGROUND

			m_window.ClearBackground(RAYWHITE);
			m_window.DrawFPS();
			DrawText("Press W and S to move forward and backward.", 25, 25, 20, LIGHTGRAY);
			DrawText("Press A and D to turn left and right.", 25, 50, 20, LIGHTGRAY);
			DrawText("Press Q and E to rotate the turret.", 25, 75, 20, LIGHTGRAY);
			DrawText("Press C to fire a bullet.", 25, 100, 20, LIGHTGRAY);

			//	LEVEL

			m_root->Draw();
		}
		EndDrawing();
	}

	system("pause");
}