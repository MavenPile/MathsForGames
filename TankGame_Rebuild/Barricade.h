#pragma once
#include "SpriteObject.h"

class Barricade : public SpriteObject
{
public:
	//	CONSTRUCTORS

	Barricade();
	Barricade(char i, float size, int x, int y, raylib::Texture2D* sprite);
	Barricade(float sizeX, float sizeY, int posX, int posY);
	Barricade(Math::Vector3& normal, float offset);
	~Barricade();

	//	METHODS

	void OnDraw() override;
};

