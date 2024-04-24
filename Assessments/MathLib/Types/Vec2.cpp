#include "MathLib/Types/Vec2.h"
#include "MathLib/MathFunctions.h"
namespace MathLib
{
	Vec2::Vec2()
		: x{ 0.f }, y{ 0.f }
	{
	}

	Vec2::Vec2(float _scalar)
		: x{ _scalar }, y{ _scalar }
	{
	}

	Vec2::Vec2(float _x, float _y)
		: x{ _x }, y{ _y }
	{
	}

	Vec2::Vec2(initializer_list<float> _values)
	{
		for (size_t i = 0; i < VEC_2_SIZE; ++i)
		{
			data[i] = *(_values.begin() + i);
		}
	}

	Vec2::Vec2(Vector2 _pos)
		: x{ _pos.x }, y{ _pos.y }
	{
	}

	Vec2::Vec2(const Vec2& _other)
		: x{ _other.x }, y{ _other.y }
	{
	}

	Vec2::Vec2(Vec2&& _other) noexcept
		: x{ _other.x }, y{ _other.y }
	{
		_other.x = 0.f;
		_other.y = 0.f;
	}

	Vec2::~Vec2() = default;

	Vec2 Vec2::Add(const Vec2& _lhs, const Vec2& _rhs)
	{
		return {};
	}

	Vec2 Vec2::Subtract(const Vec2& _lhs, const Vec2& _rhs)
	{
		return {};
	}

	Vec2 Vec2::Scale(const Vec2& _lhs, float _rhs)
	{
		return {};
	}

	Vec2 Vec2::Normalised(const Vec2& _vec)
	{
		return {};
	}

	float Vec2::Distance(const Vec2& _a, const Vec2& _b)
	{
		return 0;
	}

	float Vec2::Dot(const Vec2& _lhs, const Vec2& _rhs)
	{
		return 0;
	}

	Vec2 Vec2::Lerp(const Vec2& _a, const Vec2& _b, float _t)
	{
		return {};
	}

	Vec2 Vec2::CreateRotationVector(float _radians)
	{
		return {};
	}

	float Vec2::Dot(const Vec2& _rhs) const
	{
		return 0;
	}

	float Vec2::Magnitude() const
	{
		return 0;
	}

	float Vec2::MagnitudeSqr() const
	{
		return 0;
	}

	void Vec2::Normalise()
	{
	}

	Vec2 Vec2::Normalised() const
	{
		return {};
	}

	float Vec2::Rotation() const
	{
		return 0;
	}

	void Vec2::Rotate(float _amount)
	{
	}

	void Vec2::RotateAround(const Vec2& _pivot, float _amount)
	{
	}

	string Vec2::ToString() const
	{
		return "";
	}

	Vec2::operator Vector2() const
	{
		return { x, y };
	}

	bool Vec2::operator==(const Vec2& _other) const
	{
		return Compare(x, _other.x) && Compare(y, _other.y);
	}

	bool Vec2::operator!=(const Vec2& _other) const
	{
		return !(*this == _other);
	}

	Vec2 Vec2::operator-(const Vec2& _other) const
	{
		return {};
	}

	Vec2& Vec2::operator-=(const Vec2& _other)
	{
		return *this;
	}

	Vec2 Vec2::operator+(const Vec2& _other) const
	{
		return {};
	}

	Vec2& Vec2::operator+=(const Vec2& _other)
	{
		return *this;
	}

	Vec2 Vec2::operator*(float _other) const
	{
		return {};
	}

	Vec2& Vec2::operator*=(float _other)
	{
		return *this;
	}

	Vec2 Vec2::operator*(const Vec2& _other) const
	{
		return {};
	}

	Vec2& Vec2::operator*=(const Vec2& _other)
	{
		return *this;
	}

	Vec2& Vec2::operator=(const Vec2& _other)
	{

		if (*this == _other)
			return *this;

		x = _other.x;
		y = _other.y;

		return *this;
	}

	Vec2& Vec2::operator=(Vec2&& _other) noexcept
	{

		if (*this == _other)
			return *this;

		x = _other.x;
		y = _other.y;

		_other.x = 0.f;
		_other.y = 0.f;

		return *this;
	}

	Vec2& Vec2::operator=(Vector2 _other)
	{

		x = _other.x;
		y = _other.y;

		return *this;
	}

	Vec2 operator*(float _lhs, const Vec2& _rhs)
	{
		return {};
	}
}
