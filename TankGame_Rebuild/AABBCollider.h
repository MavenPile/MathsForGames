#pragma once

#include "Collider.h"

struct AABBCollider : public Collider
{
	//	MEMBER VARIABLES

	Math::Vector3 m_min, m_max;

	//	CONSTRUCTORS

	AABBCollider() {}

	AABBCollider(const Math::Vector3& min, const Math::Vector3& max) : m_min(min), m_max(max) {}

	//	MEMBER METHODS

	Math::Vector3 Centre() const
	{
		return (m_min + m_max) * 0.5f;
	}

	Math::Vector3 Extents() const
	{
		return { abs(m_max.x - m_min.x) * 0.5f,
				abs(m_max.y - m_min.y) * 0.5f, 1 };
	}

	std::vector<Math::Vector3> Corners() const
	{
		std::vector<Math::Vector3> corners(4);

		corners[0] = m_min;
		corners[1] = { m_min.x,m_max.y, 1 };
		corners[2] = m_max;
		corners[3] = { m_max.x,m_min.y,1 };

		return corners;
	}

	void Fit(const Math::Vector3* points, unsigned int count)
	{
		m_min = { FLT_MAX,FLT_MAX,1 };
		m_max = { FLT_MIN,FLT_MIN,1 };

		for (unsigned int i = 0; i < count; i++, points++)
		{
			m_min = Math::Vector3::MinV(m_min, *points);
			m_max = Math::Vector3::MaxV(m_max, *points);
		}
	}

	void Fit(const std::vector<Math::Vector3>& points)
	{
		m_min = { FLT_MAX,FLT_MAX,1 };
		m_max = { -FLT_MIN,-FLT_MIN,1 };

		for (auto& p : points)
		{
			m_min = Math::Vector3::MinV(m_min, p);
			m_max = Math::Vector3::MaxV(m_max, p);
		}
	}

	bool Overlaps(const Math::Vector3& p) const
	{
		return !(p.x < m_min.x || p.y < m_min.y || p.x > m_max.x || p.y > m_max.y);
	}

	bool Overlaps(const AABBCollider& other) const
	{
		return !(m_max.x < other.m_min.x || m_max.y < other.m_min.y || m_min.x > other.m_max.x || m_min.y > other.m_max.y);
	}

	Math::Vector3 ClosestPoint(const Math::Vector3& p)
	{		
		return Math::Vector3::ClampV(p, m_min, m_max);
	}

	bool isEmpty()
	{
		if (m_min.x == FLT_MAX || m_min.y == FLT_MAX)
		{
			if (m_max.x == FLT_MAX || m_max.y == FLT_MAX)
			{
				return true;
			}
		}

		return false;

	}

	void empty()
	{
		m_min = { FLT_MAX,FLT_MAX,1 };
		m_max = { FLT_MAX,FLT_MAX,1 };
	}

	void SetToTransformedBox(const Math::Matrix3& m)
	{
		if (isEmpty())
		{
			empty();
			return;
		}

		if (m.m1 > 0.f) {
			m_min.x += m.m1 * m_min.x;
			m_max.x += m.m1 * m_max.x;
		} else {
			m_min.x += m.m1 * m_max.x;
			m_max.x += m.m1 * m_min.x; }

		if (m.m4 > 0.f) {
			m_min.y += m.m4 * m_min.x;
			m_max.y += m.m4 * m_max.x;
		} else {
			m_min.y += m.m4 * m_max.x;
			m_max.y += m.m4 * m_min.x; }

		if (m.m7 > 0.f) {
			m_min.z += m.m7 * m_min.x;
			m_max.z += m.m7 * m_max.x;
		} else {
			m_min.z += m.m7 * m_max.x;
			m_max.z += m.m7 * m_min.x; }



		if (m.m2 > 0.f) {
			m_min.x += m.m2 * m_min.x;
			m_max.x += m.m2 * m_max.x;
		}
		else {
			m_min.x += m.m2 * m_max.x;
			m_max.x += m.m2 * m_min.x;
		}

		if (m.m5 > 0.f) {
			m_min.y += m.m5 * m_min.x;
			m_max.y += m.m5 * m_max.x;
		}
		else {
			m_min.y += m.m5 * m_max.x;
			m_max.y += m.m5 * m_min.x;
		}

		if (m.m8 > 0.f) {
			m_min.z += m.m8 * m_min.x;
			m_max.z += m.m8 * m_max.x;
		}
		else {
			m_min.z += m.m8 * m_max.x;
			m_max.z += m.m8 * m_min.x;
		}



		if (m.m3 > 0.f) {
			m_min.x += m.m3 * m_min.x;
			m_max.x += m.m3 * m_max.x;
		}
		else {
			m_min.x += m.m3 * m_max.x;
			m_max.x += m.m3 * m_min.x;
		}

		if (m.m6 > 0.f) {
			m_min.y += m.m6 * m_min.x;
			m_max.y += m.m6 * m_max.x;
		}
		else {
			m_min.y += m.m6 * m_max.x;
			m_max.y += m.m6 * m_min.x;
		}

		if (m.m9 > 0.f) {
			m_min.z += m.m9 * m_min.x;
			m_max.z += m.m9 * m_max.x;
		}
		else {
			m_min.z += m.m9 * m_max.x;
			m_max.z += m.m9 * m_min.x;
		}
	}
};

