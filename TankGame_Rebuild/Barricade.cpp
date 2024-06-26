#include "Barricade.h"
#include "CircleCollider.h"	
#include "AABBCollider.h"
#include "PlaneCollider.h"

Barricade::Barricade()
{

}

Barricade::Barricade(char i, float size, int x, int y, raylib::Texture2D* sprite)
{
	m_localPos = Math::Vector3(x, y, 1);
	m_sprite = sprite;
	SetParent(GameObject::GetRoot());

	if ('c' == i)
	{
		m_collider = new CircleCollider(m_localPos, size, this);
	}
	else if ('a' == i)
	{
		m_collider = new AABBCollider(GetWorldPosition() - Math::Vector3(size, size, 1), GetWorldPosition() + Math::Vector3(size, size, 1));
	}
}

Barricade::Barricade(float sizeX, float sizeY, int posX, int posY)
{
	m_localPos = Math::Vector3(posX, posY, 1);
	SetParent(GameObject::GetRoot());
	m_collider = new AABBCollider(GetWorldPosition() - Math::Vector3(sizeX, sizeY, 1), GetWorldPosition() + Math::Vector3(sizeX, sizeY, 1));
}

Barricade::Barricade(Math::Vector3& normal, float offset)
{
	m_localPos = normal;
	m_collider = new PlaneCollider(normal, offset);
	SetParent(GameObject::GetRoot());
}

Barricade::~Barricade()
{
	delete m_collider;
}

void Barricade::OnDraw()
{
	if (m_sprite != nullptr)
	{
		SpriteObject::OnDraw();
	}
	
	CircleCollider* circleCheck = dynamic_cast<CircleCollider*>(m_collider);

	if (nullptr != circleCheck)
	{
		DrawCircleLines(circleCheck->m_center.x, circleCheck->m_center.y, circleCheck->m_radius, RED);
	}

	AABBCollider* aabbCheck = dynamic_cast<AABBCollider*>(m_collider);

	if (nullptr != aabbCheck)
	{
		DrawRectangleLines(aabbCheck->m_min.x, aabbCheck->m_min.y, aabbCheck->m_max.x - aabbCheck->m_min.x, aabbCheck->m_max.y - aabbCheck->m_min.y, RED);
	}
}
