#include "Wall.h"
#include "PlaneCollider.h"
#include "raylib-cpp.hpp"

Wall::Wall(float x, float y, float offset)
{
	m_localPos = Math::Vector3(x, y, 1);
	m_collider = new PlaneCollider(x, y, offset);
}

Wall::~Wall()
{
	delete m_collider;
}

void Wall::OnDraw()
{
	PlaneCollider* planeCheck = dynamic_cast<PlaneCollider*>(m_collider);

	if (nullptr != m_collider)
	{
		DrawLine(GetWorldPosition().x - 800, GetWorldPosition().y, GetWorldPosition().x + 800, GetWorldPosition().y, RED);
	}
}