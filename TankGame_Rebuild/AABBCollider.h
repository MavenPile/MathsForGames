#pragma once
#include "Collider.h"
#include "Vector3.h"
#include <vector>
#include "Matrix3.h"

class AABBCollider : public Collider
{
public:
	//	VARIABLES

	Math::Vector3 m_min, m_max;

	//	CONSTRUCTORS

	AABBCollider();

	AABBCollider(const Math::Vector3& min, const Math::Vector3& max);

	~AABBCollider();

	//	METHODS

	Math::Vector3 Center() const;

	Math::Vector3 Extents() const;

	std::vector<Math::Vector3> Corners() const;

	void Fit(const Math::Vector3* points, unsigned int count);

	void Fit(const std::vector<Math::Vector3>& points);

	bool Overlaps(const Math::Vector3& point) const;

	bool Overlaps(const AABBCollider* other) const;

	Math::Vector3 ClosestPoint(const Math::Vector3& point);

	bool IsEmpty();

	void Empty();

	void SetToTransformedBox(const Math::Matrix3& matrix);

	void CollisionCheck(Collider* other) override;
};

