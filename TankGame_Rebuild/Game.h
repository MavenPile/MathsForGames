#pragma once
#include "raylib-cpp.hpp"
#include <vector>

class GameObject;
class Collider;
class Player;

class Game
{
public:
	//	WINDOW

	raylib::Window* m_window;
	float m_deltaTime;

	//	WORLD

	GameObject* m_root;
	std::vector<Collider*> m_colliders;
	BarrelObject* m_barrel;
	
	//	PLAYER

	Player* m_player;

	//	CONSTRUCTORS

	Game();
	Game(raylib::Window* window, raylib::Texture2D* tankSprite, raylib::Texture2D* turretSprite, raylib::Texture2D* bulletSprite, raylib::Texture2D* barrelSprite);
	~Game();

	//	METHODS

	void Run();
};

