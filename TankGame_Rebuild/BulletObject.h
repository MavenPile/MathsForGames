#pragma once
#include "SpriteObject.h"

class BulletObject : public SpriteObject
{
public:
	//	BULLET

	float m_lifeTime;
	float m_speed;

	//	CONSTRUCTORS

	BulletObject();
	BulletObject(raylib::Texture2D* bulletSprite, Math::Vector3 pos, float rot, Math::Vector3 scl);
	~BulletObject();

	//	METHODS

	void OnUpdate(float deltaTime) override;
	void OnDraw() override;
	void OnCollision(Collider* other) override;
};

