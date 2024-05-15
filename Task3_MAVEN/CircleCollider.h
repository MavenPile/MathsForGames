#pragma once

#include "Collider.h"
#include "AABBCollider.h"
#include "PlaneCollider.h"
#include "GameObject.h"

struct CircleCollider : public Collider
{
	//	MEMBER VARIABLES

	Math::Vector3 m_center;

	float m_radius;

	//	CONSTRUCTORS

	CircleCollider() {}

	CircleCollider(const Math::Vector3& p, float r, GameObject* owner) : m_center(p), m_radius(r)
	{
		m_owner = owner;
	}

	//	MEMBER METHODS

	void Fit(const Math::Vector3* points, unsigned int count)
	{
		Math::Vector3 min = { FLT_MAX,FLT_MIN,1 };
		Math::Vector3 max = { FLT_MIN,FLT_MAX,1 };

		for (unsigned int i = 0; i < count; i++, points++)
		{
			min = Min(min, *points);
			max = Max(max, *points);
		}

		m_center = (min + max) * 0.5f;
		m_radius = m_center.DistanceTo(max);
	}

	void Fit(const std::vector<Math::Vector3>& points)
	{
		Math::Vector3 min = { FLT_MAX,FLT_MIN,1 };
		Math::Vector3 max = { FLT_MIN,FLT_MAX,1 };

		for (auto& p : points)
		{
			min = Min(min, p);
			max = Max(max, p);
		}

		m_center = (min + max) * 0.5f;
		m_radius = m_center.DistanceTo(max);
	}

	bool Overlaps(const Math::Vector3& p) const
	{
		Math::Vector3 toPoint = p - m_center;

		return toPoint.MagnitudeSqr() <= (m_radius * m_radius);
	}

	bool Overlaps(AABBCollider* aabb) const
	{
		auto diff = aabb->ClosestPoint(m_center) - m_center;

		return diff.Dot(diff) <= (m_radius * m_radius);
	}

	bool Overlaps(CircleCollider* other) const
	{
		auto toPoint = other->m_center - m_center;

		float totalRad = m_radius + other->m_radius;

		return toPoint.MagnitudeSqr() <= (totalRad * totalRad);
	}

	Math::Vector3 ClosestPoint(const Math::Vector3& p) const
	{
		Math::Vector3 toPoint = p - m_center;

		if (toPoint.MagnitudeSqr() > m_radius * m_radius)
		{
			toPoint = toPoint.Normalised() * m_radius;
		}

		return m_center + toPoint;
	}

	//	COLLISION

	void CollisionCheck(Collider* other) override
	{
		CircleCollider* otherC = dynamic_cast<CircleCollider*>(other);
			//	check if other collider is a CircleCollider()

		if (otherC != nullptr)
		{
			if (Overlaps(otherC))
			{
				m_owner->OnCollision(other);
			}
		}


		AABBCollider* aabb = dynamic_cast<AABBCollider*>(other);

		if (aabb != nullptr)
		{
			if (Overlaps(aabb))
			{
				m_owner->OnCollision(other);
			}
		}

		//PlaneCollider* plane = dynamic_cast<PlaneCollider*>(other);

		//if (plane != nullptr)
		//{
		//	if (Overlaps(plane))
		//	{

		//	}
		//}
	}
};

