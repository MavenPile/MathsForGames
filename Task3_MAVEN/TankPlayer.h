#pragma once

#include "SpriteObject.h"

class TankTurret;

class TankPlayer : public SpriteObject
{
public:

	//	VARIABLES

	float m_reloadBuffer = 0.f;

	//	TURRET

	GameObject* m_turretPivot = nullptr;

	TankTurret* m_turret = nullptr;

	raylib::Texture2D* m_bulletSprite;

	//	CONSTRUCTORS

	TankPlayer();

	//	METHODS

	void SetTurretPivot(GameObject* turretPivot);

	void SetTurret(TankTurret* turret);

	void OnUpdate(float deltaTime) override;

	void OnDraw() override;
};

