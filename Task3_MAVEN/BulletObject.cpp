#include "BulletObject.h"
#include "BulletObject.h"
#include "CircleCollider.h"
#include "raylib-cpp.hpp"
#include "Vector3.h"

BulletObject::BulletObject() 
{ 
	m_collider = new CircleCollider(m_localPos, 10, this); 
	m_sprite = new raylib::Texture2D("res/Sprites/bulletBlue1_outline.png");
}

BulletObject::BulletObject(Vector3 pos, float rot, Vector3 scl)
{
	m_collider = new CircleCollider(m_localPos, 10, this);
	m_sprite = new raylib::Texture2D("res/Sprites/bulletBlue1_outline.png");
	SetParent(GameObject::GetRoot());
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
	//	DELETE

	lifetime -= deltaTime;

	if (lifetime < 0)
	{
		Destroy();
		return;
	}

	//	OBJECT MOVEMENT

	Math::Vector3 movement = GetForward() * deltaTime * m_speed;

	Translate(movement);

	//	COLLIDER MOVEMENT

	dynamic_cast<CircleCollider*>(m_collider)->m_center = m_localPos;
}

void BulletObject::OnDraw() 
{
	SpriteObject::OnDraw();

	CircleCollider* collider = dynamic_cast<CircleCollider*>(m_collider);

	DrawCircleLines(collider->m_center.x, collider->m_center.y, collider->m_radius, GREEN);
}