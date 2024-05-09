#pragma once
#include "SpriteObject.h"

class BulletObject : public SpriteObject
{
public:

	//BulletObject(Math::Vector3 localPos, float localRot, Math::Vector3 localScl);

	void Initialise();

protected:

	void OnUpdate(float deltaTime) override;
};

