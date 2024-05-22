#pragma once
#include "SpriteObject.h"
#include <iostream>

struct Collider;

class BulletObject : public SpriteObject
{
public:

	//	VARIABLES

	float lifetime = 2.f;

	const float m_speed = 500.f;

	//	CONSTRUCTORS
	
	BulletObject();

	//	METHODS

	void OnUpdate(float deltaTime) override;

	void OnDraw() override;

	void OnCollision(Collider* other) override {
		Destroy();
	}
};

