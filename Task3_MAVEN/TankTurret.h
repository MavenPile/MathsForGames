#pragma once

#include "SpriteObject.h"

class TankTurret : public GameObject
{
public:

	void Fire();

	raylib::Texture2D* m_bulletSprite;

	void SetBulletSprite(raylib::Texture2D* bulletSprite);

protected:

	void OnUpdate(float deltaTime) const;
};

