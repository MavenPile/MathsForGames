#include "Wall.h"
#include "PlaneCollider.h"
#include "raylib-cpp.hpp"
#include "AABBCollider.h"

Wall::Wall()
{
}

Wall::Wall(float sizeX, float sizeY, int x, int y)
{
	m_localPos = Math::Vector3(x, y, 1);
	SetParent(GameObject::GetRoot());
	m_collider = new AABBCollider(GetWorldPosition() - Math::Vector3(sizeX, sizeY, 1), GetWorldPosition() + Math::Vector3(sizeX, sizeY, 1));
}

Wall::~Wall()
{
	delete m_collider;
}

void Wall::OnDraw()
{
	AABBCollider* aabbCheck = dynamic_cast<AABBCollider*>(m_collider);

	if (nullptr != aabbCheck)
	{
		DrawRectangleLines(aabbCheck->m_min.x, aabbCheck->m_min.y, aabbCheck->m_max.x - aabbCheck->m_min.x, aabbCheck->m_max.y - aabbCheck->m_min.y, RED);
	}
}