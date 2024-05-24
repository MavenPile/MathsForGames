#pragma once
#include "SpriteObject.h"

class Player : public SpriteObject
{
public:
	//	TURRET

	float m_reload;
	GameObject* m_pivot;
	SpriteObject* m_turret;
	GameObject* m_bulletSpawn;

	//	SPRITES

	raylib::Texture2D* m_bulletSprite;

	//	CONSTRUCTORS

	Player();
	Player(raylib::Texture2D* tankSprite, raylib::Texture2D* turretSprite, raylib::Texture2D* bulletSprite);
	~Player();

	//	METHODS

	void OnUpdate(float deltaTime) override;
	void OnDraw() override;
};

