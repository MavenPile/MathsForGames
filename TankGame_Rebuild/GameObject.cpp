#include "GameObject.h"

#include <algorithm>
#include "CircleCollider.h"

#include <iostream>

static GameObject* m_root;

GameObject::GameObject()
{
	m_parent = nullptr;
	m_localPos = Math::Vector3(0, 0, 1);	//	Z axis is 1 so children properly inherit translations. Z axis is NOT a direction in 2D space
	m_localRot = 0;
	m_localScale = Math::Vector3(1, 1, 1);
}

GameObject* GameObject::GetRoot()
{
	return m_root;
}

void GameObject::SetRoot(GameObject* root)
{
	m_root = root;
}

//	METHODS

void GameObject::SetParent(GameObject* newParent)
{
	if (m_parent != nullptr)
	{
		auto findIt = std::find(m_parent->m_children.begin(), m_parent->m_children.end(), this);

		if (findIt != m_parent->m_children.end())
		{
			m_parent->m_children.erase(findIt);
			m_parent = nullptr;
		}
	}

	if (newParent != nullptr)
	{
		m_parent = newParent;
		m_parent->m_children.push_back(this);
	}
}

GameObject* GameObject::GetParent()
{
	return m_parent;
}

const GameObject* GameObject::GetParent() const
{
	return m_parent;
}

GameObject* GameObject::GetChild(size_t childIndex)
{
	return m_children[childIndex];
}

const GameObject* GameObject::GetChild(size_t childIndex) const
{
	return m_children[childIndex];
}

void GameObject::Update(float deltaTime)
{
	std::vector<GameObject*> copyChildren;	//	vectors don't like being worked on as their size changes
											//	their size changes when we create bullets
											//	so we work on a vector copy that contains the children

	for (int i = 0; i < m_children.size(); i++)
	{
		copyChildren.push_back(m_children[i]);
	}

	OnUpdate(deltaTime);

	for (int i = 0; i < copyChildren.size(); i++)
	{
		copyChildren[i]->Update(deltaTime);
	}
}

void GameObject::Draw()
{
	std::vector<GameObject*> copyChildren;

	for (int i = 0; i < m_children.size(); i++)
	{
		copyChildren.push_back(m_children[i]);
	}

	OnDraw();

	for (int i = 0; i < copyChildren.size(); i++)
	{
		copyChildren[i]->Draw();
	}
}

float GameObject::AngleFrom2D(float x, float y)
{
	return atan2(y, x);
}

const float GameObject::AngleFrom2D(float x, float y) const
{
	return atan2(y, x);
}

//	LOCAL POS/ROT/SCALE METHODS

Math::Vector3 GameObject::GetLocalPosition() const
{
	return Math::Vector3();
}

void GameObject::SetLocalPosition(Math::Vector3 newPos)
{
	m_localPos = newPos;
}

void GameObject::SetLocalPosition(float newX, float newY)
{
	m_localPos = Math::Vector3(newX, newY, m_localPos.z);
}

float GameObject::GetLocalRotation() const
{
	return m_localRot;
}

void GameObject::SetLocalRotation(float newRot)
{
	m_localRot = newRot;
}

Math::Vector3 GameObject::GetLocalScale() const
{
	return m_localScale;
}

void GameObject::SetLocalScale(Math::Vector3 newScale)
{
	m_localScale = newScale;
}

void GameObject::SetLocalScale(float newX, float newY)
{
	m_localScale = Math::Vector3(newX, newY, m_localScale.z);
}

Math::Vector3 GameObject::GetForward() const
{
	auto mat = GetWorldMatrix();
	
	return Math::Vector3(mat[0], mat[1], mat[2]);
}

Math::Matrix3 GameObject::GetLocalMatrix() const
{
	return Math::Matrix3::MakeTranslation(m_localPos) * 
			Math::Matrix3::MakeRotateZ(m_localRot) * 
			Math::Matrix3::MakeScale(m_localScale.x, m_localScale.y);
}

void GameObject::Translate(float x, float y)
{
	m_localPos += Math::Vector3(x, y, 0);
}

void GameObject::Translate(Math::Vector3 translation)
{
	m_localPos += translation;
}

void GameObject::Rotate(float radians)
{
	m_localRot += radians;
}

void GameObject::Scale(float x, float y)
{
	m_localScale *= Math::Vector3(x, y, 1);
}

void GameObject::Scale(Math::Vector3 scalar)
{
	m_localScale *= scalar;
}

//	WORLD POS/ROT/SCALE METHODS

Math::Vector3 GameObject::GetWorldPosition() const
{
	Math::Matrix3 worldMat = GetWorldMatrix();
	
	return Math::Vector3(worldMat.m7, worldMat.m8, worldMat.m9);
}

float GameObject::GetWorldRotation() const
{
	Math::Vector3 fwd = GetForward();

	return AngleFrom2D(fwd.x, fwd.y);
}

Math::Vector3 GameObject::GetWorldScale() const
{
	Math::Matrix3 myTransform = GetWorldMatrix();
	
	return Math::Vector3(Math::Vector3(myTransform.m1, myTransform.m2, 0).Magnitude(),
						Math::Vector3(myTransform.m4, myTransform.m5, 0).Magnitude(),
						1.f);
}

Math::Matrix3 GameObject::GetWorldMatrix() const
{
	if (nullptr == m_parent)
	{
		return GetLocalMatrix();
	}
	else
	{
		return m_parent->GetWorldMatrix() * GetLocalMatrix();
	}
}

void GameObject::GenerateCircleCollider(float r)
{
	if (m_collider != nullptr)
	{
		delete m_collider;
	}

	m_collider = new CircleCollider(m_localPos, r, this);
}

void GameObject::Destroy()
{	
	for (int i = 0; i < m_children.size(); i++)
	{
		m_children[i]->Destroy();

		std::cout << "Destroyed Object" << std::endl;
	}

	m_parent->m_children.erase(std::remove(m_parent->m_children.begin(), m_parent->m_children.end(), this), m_parent->m_children.end());

	this->m_parent = nullptr;
}

void GameObject::GetAllChildColliders(std::vector<Collider*>& colVec)
{
	if (m_collider != nullptr)
	{
		colVec.push_back(m_collider);
	}

	for (int i = 0; i < m_children.size(); i++)
	{
		m_children[i]->GetAllChildColliders(colVec);
	}
}
