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

Player::Player(raylib::Texture2D* tankSprite, raylib::Texture2D* turretSprite, raylib::Texture2D* bulletSprite)
{
	//	TANK

	m_collider = new CircleCollider(m_localPos, 50, this);
	m_sprite = tankSprite;

	//	TURRET

	m_reload = 0.f;

	m_pivot = new GameObject;
	m_pivot->SetParent(this);

	m_turret = new SpriteObject;
	m_turret->SetParent(m_pivot);
	m_turret->SetLocalPosition(35, 0);
	m_turret->m_sprite = turretSprite;
	m_bulletSprite = bulletSprite;

	m_bulletSpawn = new GameObject;
	m_bulletSpawn->SetParent(m_pivot);
	m_bulletSpawn->SetLocalPosition(60, 0);
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

	CircleCollider* colliderCheck = dynamic_cast<CircleCollider*>(m_collider);

	if (nullptr != colliderCheck)
	{
		colliderCheck->m_center = m_localPos;
	}

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
		BulletObject* bullet = new BulletObject(m_bulletSprite, m_bulletSpawn->GetWorldPosition(), m_bulletSpawn->GetWorldRotation(), m_bulletSpawn->GetWorldScale());

		//std::cout << "Fired Bullet" << std::endl;

		m_reload = GetTime() + 1;
	}
}

void Player::OnDraw()
{
	SpriteObject::OnDraw();

	CircleCollider* colliderCheck = dynamic_cast<CircleCollider*>(m_collider);

	if (nullptr != colliderCheck)
	{
		DrawCircleLines(colliderCheck->m_center.x, colliderCheck->m_center.y, colliderCheck->m_radius, BLUE);
	}
}
