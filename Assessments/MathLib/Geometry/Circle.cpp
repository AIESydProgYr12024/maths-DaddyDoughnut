#include "MathLib/Geometry/Circle.h"

#include "MathLib/Geometry/Hit.h"
#include "MathLib/MathFunctions.h"

namespace MathLib
{
	Circle::Circle() = default;

	Circle::Circle(Vec2 _center, float _radius)
		: center{ std::move(_center) }, radius{ _radius }
	{
	}

	Circle::Circle(const Circle& _other) = default;

	Circle::Circle(Circle&& _other) noexcept
		: center{ std::move(_other.center) }, radius{ _other.radius }
	{
	}

	Circle::~Circle() = default;

	bool Circle::Overlaps(const Rect& _rect) const
	{
		return false;
	}

	// Returns a hit pointer if the Circle collides with the point
	Hit* Circle::Intersects(const Vec2& _point) const
	{
		const float distance = Vec2::Distance(center, _point);

		if (distance > radius)
			return nullptr;

		const Vec2 closestPoint = center + Vec2::Normalised(_point - center) * radius;
		const Vec2 delta = closestPoint - _point;

		return new Hit
		{
			closestPoint,
			Vec2::Normalised(delta),
			delta
		};
	}

	// Returns a hit pointer if the Circle collides with another Circle
	Hit* Circle::Intersects(const Circle& _circle) const
	{
		const float distance = Vec2::Distance(center, _circle.center);
		if (distance >= radius + _circle.radius)
			return nullptr;

		const Vec2 normal = Vec2::Normalised(_circle.center - center);
		const Vec2 closestPoint = center + normal * radius;

		const float overlapLength = radius + _circle.radius - distance;
		const Vec2 delta = normal * overlapLength;

		return new Hit
		{
			closestPoint,
			normal,
			delta
		};
	}

	// Equality operator
	bool Circle::operator==(const Circle& _other) const
	{
		return center == _other.center && Compare(radius, _other.radius);
	}

	// Inequality operator
	bool Circle::operator!=(const Circle& _other) const
	{
		return !(*this == _other);
	}

	// Copy constructor
	Circle& Circle::operator=(const Circle& _other) = default;

	// Move constructor
	Circle& Circle::operator=(Circle&& _other) noexcept
	{
		if (*this == _other)
			return *this;

		center = std::move(_other.center);
		radius = _other.radius;

		_other.radius = 0.f;

		return *this;
	}
}