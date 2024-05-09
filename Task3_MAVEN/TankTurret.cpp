#include "TankTurret.h"
#include "BulletObject.h"

void TankTurret::Fire()
{
	BulletObject* bullet = new BulletObject();

	bullet->m_sprite = m_bulletSprite;

	bullet->SetParent(GetRoot());

	bullet->SetLocalPosition(GetWorldPosition());
	bullet->SetLocalRotation(GetWorldRotation());
	bullet->SetLocalScale(GetWorldScale());
}

void TankTurret::SetBulletSprite(raylib::Texture2D* bulletSprite)
{
	m_bulletSprite = bulletSprite;
}

void TankTurret::OnUpdate(float deltaTime) const
{

}
