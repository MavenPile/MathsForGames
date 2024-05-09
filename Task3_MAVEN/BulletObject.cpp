#include "BulletObject.h"

//BulletObject::BulletObject(Math::Vector3 localPos, float localRot, Math::Vector3 localScl)
//{
//	SetLocalPosition(localPos);
//
//	SetLocalRotation(localRot);
//
//	SetLocalScale(localScl);
//}

void BulletObject::Initialise()
{
	raylib::Texture2D bulletSprite("res/Sprites/bulletBlue1_outline.png");

	m_sprite = &bulletSprite;
}


void BulletObject::OnUpdate(float deltaTime)
{
	const float SPEED = 500.f;

	Math::Vector3 vel;

	Math::Vector3 DIRECTION = GetForward();

	DIRECTION.Normalise();	//	sets magnitude to 1

	vel = DIRECTION * SPEED;

	Math::Vector3 finalVel = vel * deltaTime;

	Translate(finalVel);
}
