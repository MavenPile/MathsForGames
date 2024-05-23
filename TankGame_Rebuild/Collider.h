#pragma once

class GameObject;

class Collider
{
public:
	
	GameObject* m_owner = nullptr;

	virtual void CollisionCheck(Collider* other) {};
};

