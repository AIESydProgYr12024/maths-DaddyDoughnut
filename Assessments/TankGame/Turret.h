#pragma once

#include "MathLib/Scene/SceneObject.h"
#include "MathLib/Scene/SpriteObject.h"
#include "MathLib/Types/Mat3.h"

using MathLib::SpriteObject;
using MathLib::SceneObject;
using MathLib::Mat3;

class Turret : public SceneObject
{
public:
	Turret(Texture2D* _texture);

public:
	void SetRadius(const float _radius);
	void Move(float _dt, float _speed);

private:
	float m_radius;
	SpriteObject* m_sprite;
};


