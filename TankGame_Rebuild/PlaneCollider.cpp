#include "PlaneCollider.h"
#include "CircleCollider.h"
#include "AABBCollider.h"

PlaneCollider::PlaneCollider(float x, float y, float offset)
{
	m_normal = Math::Vector3(x, y, 1);
	m_offset = offset;
}

PlaneCollider::PlaneCollider(const Math::Vector3& normal, float offset)
{
	m_normal = normal;
	m_offset = offset;
}

PlaneCollider::PlaneCollider(const Math::Vector3& p1, const Math::Vector3& p2)
{
	auto v = p2 - p1;
	v.Normalise();

	m_normal.x = -v.y;
	m_normal.y = v.x;

	m_offset = -p1.Dot(m_normal);
}

PlaneCollider::PlaneCollider(const Math::Vector3& p1, const Math::Vector3& p2, const Math::Vector3& p3)
{
	auto v1 = (p2 - p1).Normalised();
	auto v2 = (p3 - p1).Normalised();

	m_normal = v1.Cross(v2);

	m_offset = -p1.Dot(m_normal);
}

float PlaneCollider::DistanceTo(const Math::Vector3& point) const
{
	return point.Dot(m_normal) + m_offset;
}

const Math::Vector3& PlaneCollider::ClosestPoint(const Math::Vector3& point) const
{
	return point - m_normal * DistanceTo(point);
}

PlaneCollider::ePlaneResult PlaneCollider::TestSide(const Math::Vector3& point) const
{
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

PlaneCollider::ePlaneResult PlaneCollider::TestSide(const CircleCollider& circle) const
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

PlaneCollider::ePlaneResult PlaneCollider::TestSide(const AABBCollider& aabb) const
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