#include "MathLib/Scene/SceneObject.h"
#include "MathLib/Geometry/Rect.h"
#include "MathLib/Types/Vec2.h"

using MathLib::SceneObject;
using MathLib::Rect;
using MathLib::Vec2;

#pragma once
class Wall final : public SceneObject
{
public:
	Wall();
	Wall(Vec2 _center, Vec2 _extents);
	~Wall();

public:
	void Draw(Color _color);
	Rect* GetCollider();

private:
	Rect* m_collider;
};

