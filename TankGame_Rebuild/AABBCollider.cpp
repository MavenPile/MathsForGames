#include "AABBCollider.h"
#include <iostream>

AABBCollider::AABBCollider()
{

}

AABBCollider::AABBCollider(const Math::Vector3& min, const Math::Vector3& max)
{
	m_min = min;
	m_max = max;
}

AABBCollider::~AABBCollider()
{

}

Math::Vector3 AABBCollider::Center() const
{
	return (m_min + m_max) * 0.5f;
}

Math::Vector3 AABBCollider::Extents() const
{
	return { abs(m_max.x - m_min.x) * 0.5f,
			abs(m_max.y - m_min.y) * 0.5f, 1 };
}

std::vector<Math::Vector3> AABBCollider::Corners() const
{
	std::vector<Math::Vector3> corners(4);

	corners[0] = m_min;
	corners[1] = { m_min.x,m_max.y, 1 };
	corners[2] = m_max;
	corners[3] = { m_max.x,m_min.y,1 };

	return corners;
}

void AABBCollider::Fit(const Math::Vector3* points, unsigned int count)
{
	m_min = { FLT_MAX,FLT_MAX,1 };
	m_max = { FLT_MIN,FLT_MIN,1 };

	for (unsigned int i = 0; i < count; i++, points++)
	{
		m_min = Math::Vector3::MinV(m_min, *points);
		m_max = Math::Vector3::MaxV(m_max, *points);
	}
}

void AABBCollider::Fit(const std::vector<Math::Vector3>& points)
{
	m_min = { FLT_MAX,FLT_MAX,1 };
	m_max = { -FLT_MIN,-FLT_MIN,1 };

	for (auto& p : points)
	{
		m_min = Math::Vector3::MinV(m_min, p);
		m_max = Math::Vector3::MaxV(m_max, p);
	}
}

bool AABBCollider::Overlaps(const Math::Vector3& point) const
{
	return !(point.x < m_min.x || point.y < m_min.y || point.x > m_max.x || point.y > m_max.y);
}

bool AABBCollider::Overlaps(const AABBCollider* other) const
{
	return !(m_max.x < other->m_min.x || m_max.y < other->m_min.y || m_min.x > other->m_max.x || m_min.y > other->m_max.y);
}

Math::Vector3 AABBCollider::ClosestPoint(const Math::Vector3& point)
{
	return Math::Vector3::ClampV(point, m_min, m_max);
}

bool AABBCollider::IsEmpty()
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

void AABBCollider::Empty()
{
	m_min = { FLT_MAX,FLT_MAX,1 };
	m_max = { FLT_MAX,FLT_MAX,1 };
}

void AABBCollider::SetToTransformedBox(const Math::Matrix3& matrix)
{
	if (!IsEmpty())
	{
		Empty();
		return;
	}

	for (int i = 0; i < 9; i++)
	{
		if (matrix.v[i] > 0.f)
		{
			m_min.x += matrix.v[i] * m_min.x;
			m_min.x += matrix.v[i] * m_max.x;
		}
		else
		{
			m_min.x += matrix.v[i] * m_max.x;
			m_min.x += matrix.v[i] * m_min.x;
		}
	}
}

void AABBCollider::CollisionCheck(Collider* other)
{
	//	AABB
	AABBCollider* aabb = dynamic_cast<AABBCollider*>(other);

	if (nullptr != aabb)
	{
		if (Overlaps(aabb))
		{
			std::cout << "AABB > AABB Collision Detected" << std::endl;
		}
	}
}
