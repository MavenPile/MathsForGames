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