#include "PlanetSceneObject.h"

using MathLib::Mat3;
using MathLib::Vec2;

PlanetSceneObject::PlanetSceneObject(float _radius, Color _color)
	: radius{ _radius }, color{ _color }
{
}

void PlanetSceneObject::OnRender()
{
	Mat3 gt = Global();
	const Vec2 pos = gt.GetTranslation();
	const Vec2 scale = gt.GetScale() * radius;

	DrawEllipse(
		static_cast<int>(pos.x),
		static_cast<int>(pos.y),
		scale.x,
		scale.y,
		color
	);
}
