#pragma once
#include "SpriteObject.h"

class BarrelObject : public SpriteObject
{
public:
	//	CONSTRUCTORS

	BarrelObject();

	BarrelObject(int x, int y, raylib::Texture2D* sprite);

	~BarrelObject();

	//	METHODS

	void OnDraw() override;
};

