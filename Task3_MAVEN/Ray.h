#pragma once
#include "Collider.h"

struct Ray : public Collider
{
	//	MEMBER VARIABLES
	
	Math::Vector3 m_origin;
	Math::Vector3 m_direction;
	float m_length;

	//	CONSTRUCTORS
	
	Ray(const Math::Vector3& start, const Math::Vector3& dir, float len = INFINITY)
	{
		m_origin = start, m_direction = dir, m_length = 1;
	}

	//	MEMBER METHODS

	Math::Vector3 ClosestPoint(const Math::Vector3& point)
	{
		auto p = point - m_origin;

		float t = clamp(p.Dot(m_direction), 0.f, m_length);

		return m_origin + m_direction * t;
	}

	bool Intersects(const CircleCollider& circle, Math::Vector3* I = nullptr) const
	{
		auto L = circle.m_center - m_origin;

		float t = L.Dot(m_direction);

		float dd = L.Dot(L) - t * t;

		const float ray_project = circle.m_radius * circle.m_radius - dd;

		if (ray_project < 0)
		{
			return false;
		}

		t -= sqrt(circle.m_radius * circle.m_radius - dd);

		if (t >= 0 && t <= m_length)
		{
			if (I != nullptr)
			{
				*I = m_origin + m_direction * t;
			}

			return true;
		}
		
		return false;
	}

	bool Intersects(const PlaneCollider& plane, Math::Vector3* I = nullptr) const
	{

	}
};