#pragma once

#include "MathLib/Types/Vec2.h"

namespace MathLib
{
	class Hit
	{
	public:
		Vec2 point;
		Vec2 normal;
		Vec2 delta;

	public:
		Hit();
		Hit(Vec2 _point, Vec2 _normal, Vec2 _delta);

		Hit(const Hit& _other);
		Hit(Hit& _other);

		~Hit();

	public:
		bool operator==(const Hit& _other) const;
		bool operator!=(const Hit& _other) const;

		Hit& operator=(const Hit& _other);
		Hit& operator=(Hit& _other) noexcept;
	};

}