#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include <iostream>
#include "Barricade.h"

Game::Game()
{
	//	WINDOW

	m_window = new raylib::Window(1600, 900, "Game!");
	m_deltaTime = 0.f;
	SetTargetFPS(60);

	//	WORLD

	m_root = new GameObject;
	GameObject::SetRoot(m_root);

	//	PLAYER

	m_player = new Player;
	m_player->SetParent(GameObject::GetRoot());
	m_player->SetLocalPosition(800, 450);
}

//Game::Game(raylib::Window* window, raylib::Texture2D* tankSprite, raylib::Texture2D* turretSprite, raylib::Texture2D* bulletSprite, raylib::Texture2D* barrelSprite, raylib::Texture2D* barbedSprite)
//{
//	//	WINDOW
//
//	m_window = window;
//	m_deltaTime = 0.f;
//	SetTargetFPS(60);
//
//	//	WORLD
//
//	m_root = new GameObject;
//	GameObject::SetRoot(m_root);
//
//	m_barrel = new Barricade('c', 25, 1200, 450, barrelSprite);
//
//	m_barbedWire = new Barricade('a', 25, 400, 450, barbedSprite);
//
//	//	PLAYER
//
//	m_player = new Player(tankSprite, turretSprite, bulletSprite);
//	m_player->SetParent(GameObject::GetRoot());
//	m_player->SetLocalPosition(m_window->GetWidth() / 2, m_window->GetHeight() / 2);
//}

Game::Game(raylib::Window* window, std::vector<raylib::Texture2D*> textures)
{
	//	WINDOW

	m_window = window;
	m_deltaTime = 0.f;
	SetTargetFPS(60);

	//	WORLD

	m_root = new GameObject;
	GameObject::SetRoot(m_root);

	m_barrel = new Barricade('c', 25, 1200, 450, textures[3]);

	m_barbedWire = new Barricade('a', 25, 400, 450, textures[4]);

	m_north = new Barricade(660, 10, 800, 150);
	m_south = new Barricade(660, 10, 800, 750);
	m_east = new Barricade(10, 310, 1450, 450);
	m_west = new Barricade(10, 310, 150, 450);

	//	PLAYER

	m_player = new Player(textures[0], textures[1], textures[2]);
	m_player->SetParent(GameObject::GetRoot());
	m_player->SetLocalPosition(m_window->GetWidth() / 2, m_window->GetHeight() / 2);
}

Game::~Game()
{
	delete m_root;
	delete m_player;
	delete m_barrel;
	delete m_north;
	delete m_south;
	delete m_east;
	delete m_west;
}

void Game::Run()
{
	while (!m_window->ShouldClose())
	{
		//	UPDATE

		m_deltaTime = m_window->GetFrameTime();	//	gets deltatime
		m_root->Update(m_deltaTime);	//	updates the whole level

		//	COLLISION

		m_colliders.clear();	//	clears our collider storage
		m_root->GetAllChildColliders(m_colliders);	//	fills m_colliders with pointers to the colliders of m_root and all it's children

		//std::cout << "Active Colliders: " << m_colliders.size() << std::endl;

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

			m_window->ClearBackground(RAYWHITE);
			m_window->DrawFPS();
			DrawText("Press W and S to move forward and backward.", 10, 30, 20, LIGHTGRAY);
			DrawText("Press A and D to turn left and right.", 10, 55, 20, LIGHTGRAY);
			DrawText("Press Q and E to rotate the turret.", 10, 80, 20, LIGHTGRAY);
			DrawText("Press C to fire a bullet.", 10, 105, 20, LIGHTGRAY);

			//	LEVEL

			m_root->Draw();
		}
		EndDrawing();
	}
}