#include "GameObject.h"

#include <algorithm>

GameObject::GameObject()
{
	m_parent = nullptr;
	
	m_localPosition = Math::Vector3(0, 0, 1);	//	Z axis is 1 so children properly inherit translations. Z axis is NOT a direction in 2D space
	m_localRotation = 0;
	m_localScale = Math::Vector3(1, 1, 1);
}

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

void GameObject::OnUpdate(float deltaTime)
{

}

void GameObject::OnDraw()
{

}

void GameObject::Update(float deltaTime)
{
	OnUpdate(deltaTime);

		//	TODO: iterate through children and call Update on them
}

void GameObject::Draw()
{
	OnDraw();

	//	TODO: iterate through children and call Update on them
}

Math::Vector3 GameObject::GetLocalPosition() const
{
	return Math::Vector3();
}
