#pragma once
#include "Collider.h"
#include "Vector3.h"

class CircleCollider;
class AABBCollider;

class PlaneCollider : public Collider
{
public:
	//	VARIABLES

	Math::Vector3 m_normal;
	float m_offset;

	//	CONSTRUCTORS

	PlaneCollider() { m_offset = 0.f; }
	PlaneCollider(float x, float y, float offset);
	PlaneCollider(const Math::Vector3& normal, float offset);
	PlaneCollider(const Math::Vector3& p1, const Math::Vector3& p2);
	PlaneCollider(const Math::Vector3& p1, const Math::Vector3& p2, const Math::Vector3& p3);

	//	METHODS

	float DistanceTo(const Math::Vector3& point) const;

	const Math::Vector3& ClosestPoint(const Math::Vector3& point) const;

	enum ePlaneResult : int
	{
		FRONT = 1,
		BACK = -1,
		INTERSECTS = 0
	};

	ePlaneResult TestSide(const Math::Vector3& point) const;
	ePlaneResult TestSide(const CircleCollider& circle) const;
	ePlaneResult TestSide(const AABBCollider& aabb) const;
};

