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

	PlaneCollider() {}
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

	ePlaneResult TestSide(const Math::Vector3& point) const {
		float t = point.Dot(m_normal) + m_offset;

		if (t < 0)
		{
			return ePlaneResult::BACK;
		}
		else if (t > 0)
		{
			return ePlaneResult::FRONT;
		}

		return ePlaneResult::INTERSECTS;
	}
	ePlaneResult TestSide(const CircleCollider& circle) const {
		float t = DistanceTo(circle.m_center);

		if (t > circle.m_radius)
		{
			return ePlaneResult::FRONT;
		}
		else if (t < -circle.m_radius)
		{
			return ePlaneResult::BACK;
		}

		return ePlaneResult::INTERSECTS;
	}
	ePlaneResult TestSide(const AABBCollider& aabb) const {
		bool side[2] = { false,false };

		for (auto c : aabb.Corners())
		{
			auto result = TestSide(c);
			if (result == ePlaneResult::FRONT)
			{
				side[0] = true;
			}
			else if (result == ePlaneResult::BACK)
			{
				side[1] = true;
			}
		}

		if (side[0] && !side[1])
		{
			return ePlaneResult::FRONT;
		}
		else if (!side[0] && side[1])
		{
			return ePlaneResult::BACK;
		}

		return ePlaneResult::INTERSECTS;
	}
};

