#pragma once
#include "GameObject.h"
#include "raylib-cpp.hpp"
#include "Colour.h"

class SpriteObject : public GameObject
{
public:
	//	VARIABLES

	raylib::Texture2D* m_sprite;

	Math::Vector3 m_origin;

	Math::Colour m_tint;

	//	CONSTRUCTORS

	SpriteObject();

protected:

	//	METHODS

	void OnDraw() override;
};

