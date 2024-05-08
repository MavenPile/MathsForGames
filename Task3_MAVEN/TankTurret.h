#pragma once

#include "SpriteObject.h"

class TankPlayer;

class TankTurret : public SpriteObject
{
public:

	TankTurret(TankPlayer* parent);

protected:

	void OnUpdate(float deltaTime) const;
};

