#pragma once

#include "SpriteObject.h"

class TankTurret;

class TankPlayer : public SpriteObject
{
public:

	GameObject* m_turretPivot;

	void SetTurretPivot(GameObject* turretPivot);

	TankTurret* m_turret;

	void SetTurret(TankTurret* turret);

	float reloadBuffer = 0.f;

protected:

	void OnUpdate(float deltaTime) override;


};

