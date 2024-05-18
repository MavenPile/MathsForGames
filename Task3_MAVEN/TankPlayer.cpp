#include "TankPlayer.h"
#include "TankTurret.h"
#include "CircleCollider.h"

#include <iostream>

TankPlayer::TankPlayer()
{
	m_collider = new CircleCollider(m_localPos, 50, this);
	//m_bulletSprite = raylib::Texture2D("res/Sprites/bulletBlue1_outline.png");
}

void TankPlayer::SetTurretPivot(GameObject* turretPivot)
{
	m_turretPivot = turretPivot;
}

void TankPlayer::SetTurret(TankTurret* turret)
{
	m_turret = turret;
}

void TankPlayer::OnUpdate(float deltaTime)
{
	//	MOVEMENT
	
	const float MOVESPEED = 150.f;

	float yMove = 0.f;

	if (IsKeyDown(KeyboardKey::KEY_W))
	{
		yMove += MOVESPEED;
	}
	if (IsKeyDown(KeyboardKey::KEY_S))
	{
		yMove -= MOVESPEED;
	}

	Math::Vector3 finalMove = GetForward() * (yMove * deltaTime);
		//	'finalMove' is the total displacement of position

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

	//	ROTATE TURRET

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

	m_turretPivot->Rotate(finalTRot);

	//	FIRE BULLET

	if (IsKeyDown(KeyboardKey::KEY_C) && m_reloadBuffer <= GetTime())
	{
		BulletObject* m_bullet = new BulletObject();

		m_bullet->m_sprite = &m_bulletSprite;

		m_bullet->SetParent(GetRoot());

		m_bullet->SetLocalPosition(m_turret->GetWorldPosition());
		m_bullet->SetLocalRotation(m_turret->GetWorldRotation());
		m_bullet->SetLocalScale(m_turret->GetWorldScale());

		m_reloadBuffer = GetTime() + 1;
	}

	//	UPDATE COLLIDER

	dynamic_cast<CircleCollider*>(m_collider)->m_center = m_localPos;
}

void TankPlayer::OnDraw()
{
	SpriteObject::OnDraw();

	CircleCollider* collider = dynamic_cast<CircleCollider*>(m_collider);

	DrawCircleLines(collider->m_center.x, collider->m_center.y, collider->m_radius, BLUE);
}