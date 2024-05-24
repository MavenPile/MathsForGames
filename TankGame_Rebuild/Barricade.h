#pragma once
#include "SpriteObject.h"

class Barricade : public SpriteObject
{
public:
	//	CONSTRUCTORS

	Barricade();
	Barricade(char i, float size, int x, int y, raylib::Texture2D* sprite);
	~Barricade();

	//	METHODS

	void OnDraw() override;
};

