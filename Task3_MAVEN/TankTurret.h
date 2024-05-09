#pragma once

#include "SpriteObject.h"

class TankTurret : public GameObject
{
public:

	void Fire();

protected:

	void OnUpdate(float deltaTime) const;
};

