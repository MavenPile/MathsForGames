#pragma once
#include "SpriteObject.h"
#include "CircleCollider.h"
#include "Vector3.h"

struct BarrelObject : public SpriteObject
{
	BarrelObject(Math::Vector3 v) {
		m_localPos = v;
		m_collider = new CircleCollider(m_localPos, 25, this);
	}

	void OnDraw() override
	{
		SpriteObject::OnDraw();

		CircleCollider* collider = dynamic_cast<CircleCollider*>(m_collider);

		DrawCircleLines(collider->m_center.x, collider->m_center.y, collider->m_radius, RED);
	}
};

