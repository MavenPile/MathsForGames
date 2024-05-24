#include "CircleCollider.h"
#include <iostream>
#include "GameObject.h"
#include "Player.h"
#include "AABBCollider.h"
#include "PlaneCollider.h"

CircleCollider::CircleCollider(const Math::Vector3& center, float radius, GameObject* owner)
{
	m_center = center;
	m_radius = radius;
	m_owner = owner;
}

void CircleCollider::Fit(const Math::Vector3* points, unsigned int count)
{
	Math::Vector3 min = { FLT_MAX,FLT_MIN,1 };
	Math::Vector3 max = { FLT_MIN,FLT_MAX,1 };

	for (unsigned int i = 0; i < count; i++, points++)
	{
		min = Math::Vector3::MinV(min, *points);
		max = Math::Vector3::MaxV(max, *points);
	}

	m_center = (min + max) * 0.5f;
	m_radius = m_center.DistanceTo(max);
}

void CircleCollider::Fit(const std::vector<Math::Vector3>& points)
{
	Math::Vector3 min = { FLT_MAX,FLT_MIN,1 };
	Math::Vector3 max = { FLT_MIN,FLT_MAX,1 };

	for (auto& p : points)
	{
		min = Math::Vector3::MinV(min, p);
		max = Math::Vector3::MaxV(max, p);
	}

	m_center = (min + max) * 0.5f;
	m_radius = m_center.DistanceTo(max);
}

bool CircleCollider::Overlaps(const Math::Vector3& p) const
{
	Math::Vector3 toPoint = p - m_center;

	return toPoint.MagnitudeSqr() <= (m_radius * m_radius);
}

bool CircleCollider::Overlaps(CircleCollider* other) const
{
	auto toPoint = other->m_center - m_center;	//	distance between centers of circles

	float totalRad = m_radius + other->m_radius;	//	radii of both circles combined
		
	return toPoint.MagnitudeSqr() <= (totalRad * totalRad);	//	if |toPoint| <= |totalRad|, return true
}

bool CircleCollider::Overlaps(AABBCollider* other) const
{
	auto diff = other->ClosestPoint(m_center) - m_center;	//	distance between m_center and aabb.ClosestPoint()

	return diff.Dot(diff) <= (m_radius * m_radius);	//	if |diff| <= |m_radius|, return true
}

bool CircleCollider::Overlaps(PlaneCollider* other) const
{
	auto diff = other->ClosestPoint(m_center) - m_center;
	
	return diff.Dot(diff) <= (m_radius * m_radius);
}

Math::Vector3 CircleCollider::ClosestPoint(const Math::Vector3& p) const
{
	Math::Vector3 toPoint = p - m_center;
	
	if (toPoint.MagnitudeSqr() > m_radius * m_radius)
	{
		toPoint = toPoint.Normalised() * m_radius;
	}
	
	return m_center + toPoint;
}

bool CircleCollider::operator==(const CircleCollider* other) const
{
	if (m_center != other->m_center || m_radius != other->m_radius || m_owner != other->m_owner)
	{
		return false;
	}

	return true;
}

bool CircleCollider::operator!=(const CircleCollider* other) const
{
	return !(*this == other);
}

void CircleCollider::CollisionCheck(Collider* other)
{
	//	CIRCLE
	CircleCollider* circle = dynamic_cast<CircleCollider*>(other);

	if (circle != nullptr)
	{
		if (Overlaps(circle))
		{
			std::cout << "Circle > Circle Collision Detected" << std::endl;

			m_owner->OnCollision(other);
		}
	}

	//	AABB
	AABBCollider* aabb = dynamic_cast<AABBCollider*>(other);

	if (nullptr != aabb)
	{
		if (Overlaps(aabb))
		{
			std::cout << "Circle > AABB Collision Detected" << std::endl;

			m_owner->OnCollision(other);
		}
	}

	//	PLANE
	PlaneCollider* plane = dynamic_cast<PlaneCollider*>(other);

	if (nullptr != plane)
	{
		if (Overlaps(plane))
		{
			std::cout << "Circle > Plane Collision Detected" << std::endl;

			m_owner->OnCollision(other);
		}
	}
}
