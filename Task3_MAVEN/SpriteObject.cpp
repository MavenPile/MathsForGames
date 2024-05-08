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
	float rot = Rad2Deg(GetWorldRotation());
	Math::Vector3 scl = GetWorldScale();

	m_sprite->Draw(
		raylib::Rectangle(0, 0, (float)m_sprite->width, (float)m_sprite->height),
		raylib::Rectangle(pos.x, pos.y, m_sprite->width * scl.x, m_sprite->height * scl.y),
		raylib::Vector2(m_sprite->width * m_origin.x * scl.x, m_sprite->height * m_origin.y * scl.y),
		rot,
		raylib::Color(m_tint.rgba)
	);
}