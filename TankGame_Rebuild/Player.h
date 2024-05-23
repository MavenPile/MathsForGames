#pragma once
#include "SpriteObject.h"

class Player : public SpriteObject
{
public:
	//	TURRET

	float m_reload;
	GameObject* m_pivot;
	SpriteObject* m_turret;

	//	CONSTRUCTORS

	Player();

	~Player();

	//	METHODS

	void OnUpdate(float deltaTime) override;
	void OnDraw() override;
};

