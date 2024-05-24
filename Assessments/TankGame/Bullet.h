#pragma once

#include "MathLib/Scene/SceneObject.h"
#include "MathLib/Scene/SpriteObject.h"

using MathLib::SpriteObject;
using MathLib::SceneObject;

class Bullet : public SceneObject
{
public:
	Bullet(Texture2D* _texture);

public:
	void SetRadius(const float _radius);

private:
	float m_radius;
	SpriteObject* m_sprite;
};
