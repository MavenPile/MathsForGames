#pragma once
#include <vector>
#include <iostream>
#include "raylib-cpp.hpp"

struct GameObject;
struct Collider;
struct TankPlayer;
struct SpriteObject;

class Game {
public:
	//	WINDOW

	int m_screenWidth;
	int m_screenHeight;
	raylib::Window m_window;
	float m_deltaTime;

	//	WORLD

	GameObject* m_root;
	std::vector<Collider*> m_colliders;

	//	PLAYER

	TankPlayer* m_player;
	
	//	CONSTRUCTORS

	Game();

	Game(int winWidth, int winHeight);

	~Game();

	//	METHODS

	void Run();
};

