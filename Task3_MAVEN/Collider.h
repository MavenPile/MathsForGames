#pragma once

#include "ShapeUtils.h"

class GameObject;

struct Collider
{
	//	VARIABLES

	GameObject* m_owner;

	//	CONSTRUCTORS

	Collider()
	{
		m_owner = nullptr;
	}

	Collider(GameObject* owner)
	{
		m_owner = owner;
	}

	//	UTILITIES

	virtual void CollisionCheck(Collider* other) {}
};

