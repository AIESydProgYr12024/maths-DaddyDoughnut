#include "MathLib/Geometry/Hit.h"

namespace MathLib
{
	Hit::Hit() = default;

	Hit::Hit(Vec2 _point, Vec2 _normal, Vec2 _delta)
		:point{ std::move(_point) }, normal{ std::move(_normal) }, delta{ std::move(_delta) }
	{
	}

	Hit::Hit(const Hit& _other) = default;

	Hit::Hit(Hit& _other)
		:point{ std::move(_other.point) }, normal{ std::move(_other.normal) }, delta{ std::move(_other.delta) }
	{
	}

	Hit::~Hit() = default;

	bool Hit::operator==(const Hit& _other) const
	{
		return point == _other.point && normal == _other.normal && delta == _other.delta;
	}

	bool Hit::operator!=(const Hit& _other) const
	{
		return !(*this == _other);
	}

	Hit& Hit::operator=(const Hit& _other) = default;

	Hit& Hit::operator=(Hit& _other) noexcept
	{
		if (*this == _other)
			return *this;

		point = std::move(_other.point);
		normal = std::move(_other.normal);
		delta = std::move(_other.delta);

		return *this;
	}
}
