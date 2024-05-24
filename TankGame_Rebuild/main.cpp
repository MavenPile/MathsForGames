#include "Game.h"
#include "raylib-cpp.hpp"

int main()
{
	//	Initialisation

	raylib::Window* window = new raylib::Window(1600, 900, "Game!");
	raylib::Texture2D tankSprite("Sprites/tankBody_blue_outline.png");
	raylib::Texture2D turretSprite("Sprites/tankBlue_barrel1_outline.png");
	raylib::Texture2D bulletSprite("Sprites/bulletBlue1_outline.png");
	raylib::Texture2D barrelSprite("Sprites/barrelRust_top.png");
	
	Game* m_game = new Game(window, &tankSprite, &turretSprite, &bulletSprite, &barrelSprite);

	m_game->Run();
}