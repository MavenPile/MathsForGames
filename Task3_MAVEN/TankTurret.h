#pragma once

#include "SpriteObject.h"
#include "BulletObject.h"

class TankTurret : public GameObject
{
public:

	//	VARIABLES

	raylib::Texture2D* m_bulletSprite;

	//	METHODS

	void Fire()
	{
		//	Generate bullet sprite and position
		
		BulletObject* bullet = new BulletObject();

		bullet->m_sprite = m_bulletSprite;

		bullet->SetParent(GetRoot());

		bullet->SetLocalPosition(GetWorldPosition());
		bullet->SetLocalRotation(GetWorldRotation());
		bullet->SetLocalScale(GetWorldScale());

		//	Generate bullet collider


	}

	void SetBulletSprite(raylib::Texture2D* bulletSprite)
	{
		m_bulletSprite = bulletSprite;
	}
};

