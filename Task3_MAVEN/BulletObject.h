#pragma once
#include "SpriteObject.h"
#include "CircleCollider.h"

#include <iostream>

class BulletObject : public SpriteObject
{
public:

	//	VARIABLES

	float lifetime = 2.f;

	const float m_speed = 500.f;

	//	CONSTRUCTORS
	
	BulletObject() { m_collider = new CircleCollider(m_localPos, 15, this); }

	//	METHODS

	void OnUpdate(float deltaTime) override
	{
		//	DELETE
		
		lifetime -= deltaTime;

		if (lifetime < 0)
		{
			Destroy();
			return;
		}
		
		//	OBJECT MOVEMENT

		Math::Vector3 movement = GetForward() * deltaTime * m_speed;

		Translate(movement);

		//	COLLIDER MOVEMENT

		dynamic_cast<CircleCollider*>(m_collider)->m_center = m_localPos;
	}

	void OnCollision(Collider* other) override
	{
		Destroy();
	}
};

