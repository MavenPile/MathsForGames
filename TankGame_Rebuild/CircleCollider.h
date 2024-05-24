#pragma once
#include "Collider.h"
#include "Vector3.h"
#include <vector>

class AABBCollider;

class CircleCollider : public Collider
{
public:
	//	VARIABLES

	Math::Vector3 m_center;
	float m_radius;

	//	CONSTRUCTORS

	CircleCollider(const Math::Vector3& center, float radius, GameObject* owner);

	//	METHODS

	void Fit(const Math::Vector3* points, unsigned int count);
	void Fit(const std::vector<Math::Vector3>& points);

	bool Overlaps(const Math::Vector3& p) const;
	bool Overlaps(CircleCollider* other) const;
	bool Overlaps(AABBCollider* other) const;

	Math::Vector3 ClosestPoint(const Math::Vector3& p) const;

	bool operator == (const CircleCollider* other) const;
	bool operator != (const CircleCollider* other) const;

	void CollisionCheck(Collider* other) override;
};

