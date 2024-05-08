#pragma once

#include <vector>

#include "Vector3.h"
#include "Matrix3.h"

class GameObject
{
protected:
	
	//	MEMBER VARIABLES

	GameObject* m_parent;

	std::vector<GameObject*> m_children;

	Math::Vector3 m_localPosition;

	float m_localRotation;

	Math::Vector3 m_localScale;

	//	MEMBER METHODS

	virtual void OnUpdate(float deltaTime);

	virtual void OnDraw();

public:

	//	CONSTRUCTORS

	GameObject();

	//	METHODS

	void SetParent(GameObject* newParent);

	GameObject* GetParent();

	const GameObject* GetParent() const;

	GameObject* GetChild(size_t childIndex);

	const GameObject* GetChild(size_t childIndex) const;

	void Update(float deltaTime);

	void Draw();

	//	TRANSFORM METHODS

	Math::Vector3 GetLocalPosition() const;

	void SetLocalPosition(Math::Vector3 newPosition);

	void SetLocalPosition(float newX, float newY);

	Math::Vector3 GetWorldPosition() const;

	float GetLocalRotation() const;

	void SetLocalRotation(float newRotation);

	float GetWorldRotation() const;

	Math::Vector3 GetLocalScale() const;

	void SetLocalScale(Math::Vector3 newScale);

	void SetLocalScale(float newX, float newY);

	Math::Vector3 GetWorldScale() const;

	Math::Vector3 GetForward() const;

	Math::Matrix3 GetLocalMatrix() const;

	Math::Matrix3 GetWorldMatrix() const;
};