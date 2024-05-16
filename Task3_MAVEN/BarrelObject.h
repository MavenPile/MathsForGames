#pragma once
#include "SpriteObject.h"
#include "CircleCollider.h"
#include "Vector3.h"

struct BarrelObject : public SpriteObject
{
	BarrelObject(Math::Vector3 v,float r) {
		m_localPos = v;
		m_collider = new CircleCollider(m_localPos, r, this);
	}
};

