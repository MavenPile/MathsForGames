#include "Game.h"
#include "raylib-cpp.hpp"
#include <vector>

int main()
{
	//	Initialisation

	bool usingVector = true;

	raylib::Window* window = new raylib::Window(1600, 900, "Game!");

	Game* m_game;
	
	if (true == usingVector)
	{
		std::vector<raylib::Texture2D*> textures;

		textures.push_back(new raylib::Texture2D("Sprites/tankBody_blue_outline.png"));
		textures.push_back(new raylib::Texture2D("Sprites/tankBlue_barrel1_outline.png"));
		textures.push_back(new raylib::Texture2D("Sprites/bulletBlue1_outline.png"));
		textures.push_back(new raylib::Texture2D("Sprites/barrelRust_top.png"));
		textures.push_back(new raylib::Texture2D("Sprites/barricadeWood.png"));

		m_game = new Game(window, textures);
	}
	else
	{
		raylib::Texture2D tankSprite("Sprites/tankBody_blue_outline.png");
		raylib::Texture2D turretSprite("Sprites/tankBlue_barrel1_outline.png");
		raylib::Texture2D bulletSprite("Sprites/bulletBlue1_outline.png");
		raylib::Texture2D barrelSprite("Sprites/barrelRust_top.png");
		raylib::Texture2D barbedSprite("Sprites/barricadeWood.png");

		m_game = new Game(window, &tankSprite, &turretSprite, &bulletSprite, &barrelSprite, &barbedSprite);
	}

	m_game->Run();
}