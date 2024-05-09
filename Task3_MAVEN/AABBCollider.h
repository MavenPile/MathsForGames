#pragma once
#include "Collider.h"

struct AABBCollider : public Collider
{
	AABBCollider() {}

	AABBCollider(const Vector2& min, const Vector2& max) : min(min), max(max) {}
};

