#pragma once

#include "MathLib/Scene/SceneObject.h"

using MathLib::SceneObject;

class PlanetSceneObject : public SceneObject
{
public:
	float radius;
	Color color;

public:
	PlanetSceneObject(float _radius, Color _color);

protected:
	void OnRender() override;
};

