#pragma once

#include "raylib-cpp.hpp"
#include "Colour.h"
#include "GameObject.h"

class SpriteObject : public GameObject
{
public:

	//	VARIABLES

	raylib::Texture2D* m_sprite;

	Math::Vector3 m_origin;

	Math::Colour m_tint;

	//	CONSTRUCTORS

	SpriteObject()
	{
		m_sprite = nullptr;
		m_origin = Math::Vector3(0.5f, 0.5f, 0.5f);
		m_tint = Math::Colour(255, 255, 255, 255);
	}

protected:	//	METHODS

	void OnDraw() override
	{
		Math::Vector3 pos = GetWorldPosition();
		float rot = GetWorldRotation() * Rad2Deg;
		Math::Vector3 scl = GetWorldScale();

		m_sprite->Draw(
			raylib::Rectangle(0, 0, (float)m_sprite->width, (float)m_sprite->height),
			raylib::Rectangle(pos.x, pos.y, m_sprite->width * scl.x, m_sprite->height * scl.y),
			raylib::Vector2(m_sprite->width * m_origin.x * scl.x, m_sprite->height * m_origin.y * scl.y),
			rot,
			raylib::Color(m_tint.colour));
	}
};

