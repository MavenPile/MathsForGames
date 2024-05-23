#include "BulletObject.h"
#include "CircleCollider.h"

BulletObject::BulletObject()
{
	m_lifeTime = 2.f;
	m_speed = 500.f;
	m_collider = new CircleCollider(m_localPos, 10, this);
	//m_sprite = new raylib::Texture2D("Sprites/bulletBlue1_outline.png");
}

BulletObject::BulletObject(Math::Vector3 pos, float rot, Math::Vector3 scl)
{
	m_lifeTime = 2.f;
	m_speed = 500.f;
	m_collider = new CircleCollider(m_localPos, 10, this);
	//m_sprite = new raylib::Texture2D("Sprites/bulletBlue1_outline.png");
	SetLocalPosition(pos);
	SetLocalRotation(rot);
	SetLocalScale(scl);
}

BulletObject::~BulletObject()
{
	delete m_collider;
	delete m_sprite;
}

void BulletObject::OnUpdate(float deltaTime)
{
	//	LIFETIME
	
	m_lifeTime -= deltaTime;

	if (m_lifeTime < 0)
	{
		Destroy();
		return;
	}

	//	MOVEMENT

	Translate(GetForward() * deltaTime * m_speed);

	//	COLLIDER

	dynamic_cast<CircleCollider*>(m_collider)->m_center = m_localPos;
}

void BulletObject::OnDraw()
{
	SpriteObject::OnDraw();

	CircleCollider* collider = dynamic_cast<CircleCollider*>(m_collider);

	DrawCircleLines(collider->m_center.x, collider->m_center.y, collider->m_radius, GREEN);
}

void BulletObject::OnCollision(Collider* other)
{
	Destroy();
}