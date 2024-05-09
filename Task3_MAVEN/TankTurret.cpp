#include "TankTurret.h"
#include "BulletObject.h"

void TankTurret::Fire()
{
	BulletObject bullet;

	bullet.SetParent(GetRoot());

	bullet.SetLocalPosition(GetLocalPosition());
	bullet.SetLocalRotation(GetLocalRotation());
	bullet.SetLocalScale(GetLocalScale());

}

void TankTurret::OnUpdate(float deltaTime) const
{

}
