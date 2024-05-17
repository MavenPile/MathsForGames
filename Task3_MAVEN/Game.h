#pragma once
#include <vector>
#include <iostream>
#include "raylib-cpp.hpp"

struct GameObject;
struct Collider;
struct TankPlayer;
struct SpriteObject;

class Game
{
private:

	//	VARIABLES/HOLDERS/OBJECTS

	raylib::Window m_window;

	GameObject* m_root;

	std::vector<Collider*> m_colliders;

	TankPlayer* m_player;

	float m_deltaTime;

	GameObject* m_pivot;

	SpriteObject* m_turret;

public:	
	
	//	CONSTRUCTORS

	Game();

	~Game();

	//	METHODS

	void Run();
};

