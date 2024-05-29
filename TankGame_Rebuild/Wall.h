#pragma once
#include "GameObject.h"

class Wall : public GameObject
{
public:
	//	CONSTRUCTORS

	Wall();
	Wall(float sizeX, float sizeY, int x, int y);
	~Wall();

	//	METHODS

	void OnDraw() override;
};