#pragma once
#include "raylib-cpp.hpp"
#include <vector>

class GameObject;
class Collider;
class Player;
class Barricade;

class Game
{
public:
	//	WINDOW

	raylib::Window* m_window;
	float m_deltaTime;

	//	WORLD

	GameObject* m_root;
	std::vector<Collider*> m_colliders;
	Barricade* m_barrel;
	Barricade* m_barbedWire;
	
	Barricade* m_north;
	Barricade* m_south;
	Barricade* m_east;
	Barricade* m_west;

	//	PLAYER

	Player* m_player;

	//	CONSTRUCTORS

	Game();
	//Game(raylib::Window* window, raylib::Texture2D* tankSprite, raylib::Texture2D* turretSprite, raylib::Texture2D* bulletSprite, raylib::Texture2D* barrelSprite, raylib::Texture2D* barbedSprite);
	Game(raylib::Window* window, std::vector<raylib::Texture2D*> textures);
	~Game();

	//	METHODS

	void Run();
};

