#include "TankPlayer.h"
#include "TankTurret.h"

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

	m_turretPivot->Rotate(finalTRot);

	//	BULLET

	float reload = 0.f;

	if (IsKeyDown(KeyboardKey::KEY_C) && reload <= GetTime())
	{
		m_turret->Fire();

		reload = GetTime() + 3;
	}

}