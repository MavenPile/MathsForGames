#pragma once
#include "GameObject.h"

class Wall : public GameObject
{
public:
	//	CONSTRUCTORS

	Wall(float x, float y, float offset);
	~Wall();

	//	METHODS

	void OnDraw() override;
};