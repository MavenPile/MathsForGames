#pragma once

#include <vector>
#include "Collider.h"

class GameObject
{
protected:
	
	//	MEMBER VARIABLES

	GameObject* m_parent;

	std::vector<GameObject*> m_children;

	Math::Vector3 m_localPos;

	float m_localRot;

	Math::Vector3 m_localScale;

	Collider* m_collider = nullptr;

	//	MEMBER METHODS

	virtual void OnUpdate(float deltaTime) {}

	virtual void OnDraw() {}

public:

	//	CONSTRUCTORS

	GameObject();

	//GameObject(GameObject* parent);

	//	METHODS

	GameObject* GetRoot();

	static void SetRoot(GameObject* root);

	void SetParent(GameObject* newParent);

	GameObject* GetParent();

	const GameObject* GetParent() const;

	GameObject* GetChild(size_t childIndex);

	const GameObject* GetChild(size_t childIndex) const;

	void Update(float deltaTime);

	void Draw();

	float AngleFrom2D(float x, float y);

	const float AngleFrom2D(float x, float y) const;

	float Rad2Deg(float radians);

	const float Rad2Deg(float radians) const;

	//	LOCAL TRANSFORM METHODS

	Math::Vector3 GetLocalPosition() const;

	void SetLocalPosition(Math::Vector3 newPos);

	void SetLocalPosition(float newX, float newY);

	float GetLocalRotation() const;

	void SetLocalRotation(float newRot);

	Math::Vector3 GetLocalScale() const;

	void SetLocalScale(Math::Vector3 newScale);

	void SetLocalScale(float newX, float newY);

	Math::Vector3 GetForward() const;

	Math::Matrix3 GetLocalMatrix() const;

	void Translate(float x, float y);

	void Translate(Math::Vector3 translation);

	void Rotate(float radians);

	void Scale(float x, float y);

	void Scale(Math::Vector3 scalar);

	//	WORLD TRANSFORM METHODS

	Math::Vector3 GetWorldPosition() const;

	float GetWorldRotation() const;

	Math::Vector3 GetWorldScale() const;

	Math::Matrix3 GetWorldMatrix() const;

	//	COLLISION

	bool CheckCollision();

	void SetCollider(Collider* collider);

	virtual void Destroy();
		//	remove itself from the children or as parent of other objects

	virtual void OnCollision(Collider* other) {}
		//	use dynamic cast to know what shapes the collision is occuring with

	void GetAllChildColliders(std::vector<Collider*> colVec);
};