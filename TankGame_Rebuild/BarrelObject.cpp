#include "BarrelObject.h"
#include "CircleCollider.h"	

BarrelObject::BarrelObject()
{

}

BarrelObject::BarrelObject(int x, int y, raylib::Texture2D* sprite)
{
	m_localPos = Math::Vector3(x, y, 1);
	m_collider = new CircleCollider(m_localPos, 25, this);
	m_sprite = sprite;
	SetParent(GameObject::GetRoot());
}

BarrelObject::~BarrelObject()
{
	delete m_collider;
}

void BarrelObject::OnDraw()
{
	SpriteObject::OnDraw();

	CircleCollider* colliderCheck = dynamic_cast<CircleCollider*>(m_collider);

	if (nullptr != colliderCheck)
	{
		DrawCircleLines(colliderCheck->m_center.x, colliderCheck->m_center.y, colliderCheck->m_radius, RED);
	}
}
