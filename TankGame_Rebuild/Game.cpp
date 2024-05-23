#include "Game.h"
#include "GameObject.h"
#include "Player.h"

Game::Game()
{
	//	WINDOW

	m_window = raylib::Window(1600, 900, "Game!");
	m_deltaTime = 0.f;

	//	WORLD

	m_root = new GameObject;
	GameObject::SetRoot(m_root);

	//	PLAYER

	m_player = new Player;
	m_player->SetParent(GameObject::GetRoot());
	m_player->SetLocalPosition(800, 450);
}

Game::Game(int winWidth, int winHeight)
{
	//	WINDOW

	m_window = raylib::Window(winWidth, winHeight, "Game!");
	m_deltaTime = 0.f;

	//	WORLD

	m_root = new GameObject;
	GameObject::SetRoot(m_root);

	//	PLAYER

	m_player = new Player;
	m_player->SetParent(GameObject::GetRoot());
	m_player->SetLocalPosition(winWidth / 2, winHeight / 2);
}

Game::~Game()
{
	delete m_root;
	delete m_player;
}

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
			DrawText("Press W and S to move forward and backward.", 25, 30, 20, LIGHTGRAY);
			DrawText("Press A and D to turn left and right.", 25, 55, 20, LIGHTGRAY);
			DrawText("Press Q and E to rotate the turret.", 25, 80, 20, LIGHTGRAY);
			DrawText("Press C to fire a bullet.", 25, 105, 20, LIGHTGRAY);

			//	LEVEL

			m_root->Draw();
		}
		EndDrawing();
	}

	system("pause");
}
