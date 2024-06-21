#include "MathLib/Geometry/Rect.h"
#include "MathLib/Geometry/Hit.h"

#include <algorithm>

namespace MathLib
{
	Rect::Rect()
		: center{ Vec2::zero }, extents{ Vec2::half }
	{
	}

	Rect::Rect(Vec2 _center, Vec2 _extents)
		: center{ std::move(_center) }, extents{ std::move(_extents) }
	{
	}

	Rect::Rect(const Rect& _other) = default;

	Rect::Rect(Rect&& _other) noexcept
		: center{ std::move(_other.center) }, extents{ std::move(_other.extents) }
	{
	}

	Rect::~Rect() = default;

	Vec2 Rect::Size() const
	{
		return center * 2.f;
	}

	Vec2 Rect::Min() const
	{
		return center - extents;
	}

	Vec2 Rect::Max() const
	{
		return center + extents;
	}

	bool Rect::Contains(const Vec2& _point) const
	{
		const Vec2 min = Min();
		const Vec2 max = Max();

		return _point.x > min.x && _point.x < max.x &&
			_point.y > min.y && _point.y < max.y;
	}

	bool Rect::Overlaps(const Circle* _circle) const
	{
		return false;
	}

	Hit* Rect::Intersects(const Vec2& _point) const
	{
		if (!Contains(_point))
			return  nullptr;

		const Vec2 vec = _point - center;
		const Vec2 overlap = extents - Vec2{ fabsf(vec.x), fabsf(vec.y) };

		Vec2 position = { 0.f };
		Vec2 normal = { 0.f };
		Vec2 delta = { 0.f };

		if (overlap.x < overlap.y)
		{
			const float sx = vec.x < 0.f ? -1.f : 1.f;
			delta.x = overlap.x * sx;
			normal.x = sx;
			position.x = center.x + extents.x * sx;

			position.y - _point.y;
		}
		else
		{
			const float sy = vec.y < 0.f ? -1.f : 1.f;
			delta.y = overlap.y * sy;
			normal.y = sy;
			position.y = center.y + extents.y * sy;

			position.x - _point.x;
		}

		return new Hit
		{
			position,
			normal,
			delta
		};
	}

	Hit* Rect::Intersects(const Rect& _rect) const
	{
		const Vec2 vec = _rect.center - center;
		const Vec2 overlap = _rect.extents + extents - Vec2{ fabsf(vec.x), fabsf(vec.y) };

		if (overlap.x <= 0 || overlap.y <= 0)
			return nullptr;

		Vec2 position = { 0.f };
		Vec2 normal = { 0.f };
		Vec2 delta = { 0.f };

		if (overlap.x < overlap.y)
		{
			const float sx = vec.x < 0.f ? -1.f : 1.f;
			delta.x = overlap.x * sx;
			normal.x = sx;
			position.x = center.x + extents.x * sx;

			position.y - _rect.center.y;
		}
		else
		{
			const float sy = vec.y < 0.f ? -1.f : 1.f;
			delta.y = overlap.y * sy;
			normal.y = sy;
			position.y = center.y + extents.y * sy;

			position.x - _rect.center.y;
		}

		return new Hit
		{
			position,
			normal,
			delta
		};
	}

	Rect::operator Rectangle()
	{
		return { center.x - extents.x, center.y - extents.y, extents.x * 2.f, extents.y * 2.f };
	}

	bool Rect::operator==(const Rect& _other) const
	{
		return center == _other.center && extents == _other.extents;
	}

	bool Rect::operator!=(const Rect& _other) const
	{
		return !(*this == _other);
	}

	Rect& Rect::operator=(const Rect& _other) = default;

	Rect& Rect::operator=(Rect&& _other) noexcept
	{
		if (*this == _other)
			return *this;

		center = std::move(_other.center);
		extents = std::move(_other.extents);

		return *this;
	}
}
