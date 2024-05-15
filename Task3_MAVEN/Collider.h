#pragma once

#include <vector>
#include "ShapeUtils.h"
#include "AABBCollider.h"
#include "CircleCollider.h"
#include "PlaneCollider.h"
#include "GameObject.h"

class GameObject;

struct Collider
{
	//	VARIABLES

	GameObject* m_owner = nullptr;

	//	UTILITIES
};

