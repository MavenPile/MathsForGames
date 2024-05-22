#pragma once

#include "SpriteObject.h"

class TankTurret;

class TankPlayer : public SpriteObject
{
public:

	//	VARIABLES

	float m_reloadBuffer = 0.f;

	//	TURRET

	GameObject* m_pivot = nullptr;

	SpriteObject* m_turret = nullptr;

	raylib::Texture2D* m_turretSprite;

	//	CONSTRUCTORS

	TankPlayer();

	~TankPlayer();

	//	METHODS

	void OnUpdate(float deltaTime) override;

	void OnDraw() override;
};

