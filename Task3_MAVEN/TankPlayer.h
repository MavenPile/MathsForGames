#pragma once

#include "SpriteObject.h"

class TankTurret;

class TankPlayer : public SpriteObject
{
public:

	//	VARIABLES

	GameObject* m_turretPivot = nullptr;

	TankTurret* m_turret = nullptr;

	float reloadBuffer = 0.f;

	//	CONSTRUCTORS

	TankPlayer();

	//	METHODS

	void SetTurretPivot(GameObject* turretPivot);

	void SetTurret(TankTurret* turret);

protected:

	void OnUpdate(float deltaTime) override;

	void OnDraw() override;
};

