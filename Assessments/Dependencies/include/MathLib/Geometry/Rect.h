#pragma once

#include "MathLib/Types/Vec2.h"

namespace MathLib
{
	class Hit;
	class Circle;

	class Rect
	{
	public:
		Vec2 center; // rec location
		Vec2 extents; // half size of rec

	public:
		Rect();
		Rect(Vec2 _center, Vec2 _extents);

		Rect(const Rect& _other);
		Rect(Rect&& _other) noexcept;

		~Rect();

	public:
		Vec2 Size() const;
		Vec2 Min() const;
		Vec2 Max() const;

		bool Contains(const Vec2& _point) const;
		bool Overlaps(const Circle* _circle) const;

		Hit* Intersects(const Vec2& _point) const;
		Hit* Intersects(const Rect& _rect) const;

	public:

		operator Rectangle();

		bool operator==(const Rect& _other) const;
		bool operator!=(const Rect& _other) const;

		Rect& operator=(const Rect& _other);
		Rect& operator=(Rect&& _other) noexcept;
	};
}