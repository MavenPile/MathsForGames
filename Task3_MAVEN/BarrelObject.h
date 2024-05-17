#pragma once
#include "SpriteObject.h"
#include "CircleCollider.h"
#include "Vector3.h"

struct BarrelObject : public SpriteObject
{
	BarrelObject() {}

	void Construct(int x, int y) {
		m_localPos = Math::Vector3(x, y, 1);
		m_collider = new CircleCollider(m_localPos, 25, this);
	}

	void OnDraw() override
	{
		SpriteObject::OnDraw();

		CircleCollider* collider = dynamic_cast<CircleCollider*>(m_collider);

		DrawCircleLines(collider->m_center.x, collider->m_center.y, collider->m_radius, RED);
	}
};

