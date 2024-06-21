#pragma once

#include "MathLib/Scene/SceneObject.h"
#include "MathLib/Scene/SpriteObject.h"
#include "MathLib/Types/Mat3.h"
#include "MathLib/Geometry/Rect.h"

using MathLib::SpriteObject;
using MathLib::SceneObject;
using MathLib::Mat3;

class Bullet : public SceneObject
{
public:
	Bullet(Texture2D* _texture);
	~Bullet();

public:
	void SetRadius(const float _radius);
	void Move(float _dt);
	MathLib::Rect* GetCollider() const;

private:
	float m_radius;
	SpriteObject* m_sprite;
	MathLib::Rect* m_collider;
	bool m_hasCollided;
};
