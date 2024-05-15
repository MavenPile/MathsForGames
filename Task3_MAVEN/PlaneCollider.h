#pragma once

#include "Collider.h"

struct PlaneCollider : public Collider
{
	//	MEMBER VARIABLES

	Math::Vector3 m_N;

	float m_d;

	//	CONSTRUCTORS

	PlaneCollider() {}

	PlaneCollider(float x, float y, float d) : m_N(x,y,1), m_d(d) {}

	PlaneCollider(const Math::Vector3& n, float d) : m_N(n), m_d(d) {}

	PlaneCollider(const Math::Vector3& p1, const Math::Vector3& p2)
	{
		auto v = p2 - p1;
		v.Normalise();

		m_N.x = -v.y;
		m_N.y = v.x;

		m_d = -p1.Dot(m_N);
	}

	PlaneCollider(const Math::Vector3& p1, const Math::Vector3& p2, const Math::Vector3& p3)
	{
		auto v1 = (p2 - p1).Normalised();
		auto v2 = (p2 - p1).Normalised();

		m_N = v1.Cross(v2);

		m_d = -p1.Dot(m_N);
	}

	//	MEMBER METHODS

	float DistanceTo(const Math::Vector3& p) const
	{
		return p.Dot(m_N) + m_d;
	}

	const Math::Vector3& ClosestPoint(const Math::Vector3& p) const
	{
		return p - m_N * DistanceTo(p);
	}

	enum ePlaneResult : int
	{
		FRONT = 1,
		BACK = -1,
		INTERSECTS = 0
	};

	ePlaneResult TestSide(const Math::Vector3& p) const
	{
		float t = p.Dot(m_N) + m_d;

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

	ePlaneResult TestSide(const CircleCollider& circle) const
	{
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

	ePlaneResult TestSide(const AABBCollider& aabb) const
	{
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

