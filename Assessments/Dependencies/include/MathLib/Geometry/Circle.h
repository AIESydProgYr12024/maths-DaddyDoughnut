#pragma once

#include "MathLib/Types/Vec2.h"

namespace MathLib
{
	class Hit;
	class Rect;

	class Circle
	{
	public:
		Vec2 center;
		float radius;

	public:
		Circle();
		Circle(Vec2 _center, float _radius);

		Circle(const Circle& _other);
		Circle(Circle&& _other) noexcept;

		~Circle();

	public:
		bool Overlaps(const Rect& _rect) const;

		Hit* Intersects(const Vec2& _point) const;
		Hit* Intersects(const Circle& _circle) const;

	public:
		bool operator==(const Circle& _other) const;
		bool operator!=(const Circle& _other) const;

		Circle& operator=(const Circle& _other);
		Circle& operator=(Circle&& _other) noexcept;
	};

}

