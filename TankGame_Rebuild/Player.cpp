#include "Player.h"
#include "CircleCollider.h"
#include "raylib-cpp.hpp"
#include "BulletObject.h"
#include <iostream>

Player::Player()
{
	//	TANK

	m_collider = new CircleCollider(m_localPos, 50, this);
	//m_sprite = new raylib::Texture2D("Sprites/tankBody_blue_outline.png");


	//	TURRET

	m_reload = 0.f;

	m_pivot = new GameObject;
	m_pivot->SetParent(this);

	m_turret = new SpriteObject;
	m_turret->SetParent(m_pivot);
	m_turret->SetLocalPosition(25, 0);
	//raylib::Texture2D turretSprite("Sprites/tankBlue_barrel1_outline.png");
	//m_turret->m_sprite = &turretSprite;

	//DrawCircleLines(m_turret->GetWorldPosition().x, m_turret->GetWorldPosition().y, 10, BLUE);
}

Player::~Player()
{
	delete m_collider;
	delete m_sprite;
	delete m_pivot;
	delete m_turret;
}

void Player::OnUpdate(float deltaTime)
{
	//	MOVEMENT

	const float MOVESPEED = 150.f;

	float yMove = 0.f;

	if (IsKeyDown(KeyboardKey::KEY_W)) {
		yMove += MOVESPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_S)) {
		yMove -= MOVESPEED;
	}

	Math::Vector3 finalMove = GetForward() * (yMove * deltaTime);

	Translate(finalMove);

	//	ROTATE

	const float ROTSPEED = 4.f;

	float rot = 0.f;

	if (IsKeyDown(KeyboardKey::KEY_A))
	{
		rot -= ROTSPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_D))
	{
		rot += ROTSPEED;
	}

	float finalRot = (rot * deltaTime);

	Rotate(finalRot);

	//	COLLIDER

	dynamic_cast<CircleCollider*>(m_collider)->m_center = m_localPos;

	//	TURRET

	const float TROTSPEED = 3.f;

	float tRot = 0.f;

	if (IsKeyDown(KeyboardKey::KEY_Q))
	{
		tRot -= TROTSPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_E))
	{
		tRot += TROTSPEED;
	}

	float finalTRot = tRot * deltaTime;

	m_pivot->Rotate(finalTRot);

	//	BULLET

	if (IsKeyDown(KeyboardKey::KEY_C) && m_reload <= GetTime())
	{
		BulletObject* bullet = new BulletObject(m_turret->GetWorldPosition(), m_turret->GetWorldRotation(), m_turret->GetWorldScale());

		m_reload = GetTime() + 1;
	}
}

void Player::OnDraw()
{
	SpriteObject::OnDraw();

	CircleCollider* colCopy = dynamic_cast<CircleCollider*>(m_collider);

	DrawCircleLines(colCopy->m_center.x, colCopy->m_center.y, colCopy->m_radius, BLUE);
}
