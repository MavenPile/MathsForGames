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
public:

	//	VARIABLES

	float m_deltaTime;

	int m_screenWidth;

	int m_screenHeight;

	//	WINDOW

	raylib::Window m_window;

	//	SPRITES

	//raylib::Texture2D* m_tankSprite;

	//raylib::Texture2D* m_turretSprite;

	//raylib::Texture2D* m_barrelSprite;

	//	WORLD

	GameObject* m_root;

	std::vector<Collider*> m_colliders;

	//	PLAYER

	TankPlayer* m_player;

	GameObject* m_pivot;

	SpriteObject* m_turret;
	
	//	CONSTRUCTORS

	Game() {}

	Game(int winWidth, int winHeight);

	~Game();

	//	METHODS

	void Run();
};

