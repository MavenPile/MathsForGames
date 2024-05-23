#pragma once

#include "Utils.h"

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

	//	METHODS

	virtual void CollisionCheck(Collider* other) {}

	//	OPERATORS
};

