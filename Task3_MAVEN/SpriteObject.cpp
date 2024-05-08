#include "SpriteObject.h"
#include "Utils.h"			//	for Rad2Deg

SpriteObject::SpriteObject()
{
	m_sprite = nullptr;
	m_origin = Math::Vector3(0.5f, 0.5f, 0.5f);
	m_tint = Math::Colour(255, 255, 255, 255);
}

void SpriteObject::OnDraw()
{
	Math::Vector3 pos = GetWorldPosition();
	float rot = GetWorldRotation() * Rad2Deg();
	Math::Vector3 scl = GetWorldScale();
}