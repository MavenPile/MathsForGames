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

	raylib::Window m_window;
	float m_deltaTime;

	//	WORLD

	GameObject* m_root;
	std::vector<Collider*> m_colliders;
	
	//	PLAYER

	Player* m_player;

	//	CONSTRUCTORS

	Game();

	Game(int winWidth, int winHeight);

	~Game();

	//	METHODS

	void Run();
};

