#pragma once

#include "raylib-cpp.hpp"
#include "Colour.h"
#include "GameObject.h"

class SpriteObject : GameObject
{
public:

	//	VARIABLES

	raylib::Texture2D* m_sprite;

	Math::Vector3 m_origin;

	Math::Colour m_tint;

	//	CONSTRUCTORS

	SpriteObject();

protected:

	void OnDraw() override;
};

