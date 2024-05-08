#pragma once

#include "SpriteObject.h"

class TankPlayer : public SpriteObject
{
public:

	GameObject* m_turret;

	TankPlayer(GameObject* turret);

protected:

	void OnUpdate(float deltaTime) override;


};

