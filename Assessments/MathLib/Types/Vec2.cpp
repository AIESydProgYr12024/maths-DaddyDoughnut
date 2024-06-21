#include "MathLib/Types/Vec2.h"
#include "MathLib/MathFunctions.h"
namespace MathLib
{
	Vec2 Vec2::one = Vec2(1.f, 1.f);
	Vec2 Vec2::zero = Vec2(0.f, 0.f);
	Vec2 Vec2::half = Vec2(.5f, .5f);
	Vec2 Vec2::up = Vec2(0.f, 1.f);
	Vec2 Vec2::down = Vec2(0.f, -1.f);
	Vec2 Vec2::left = Vec2(-1.f, 0.f);
	Vec2 Vec2::right = Vec2(1.f, 0.f);

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

	// Copy constructor
	Vec2::Vec2(const Vec2& _other)
		: x{ _other.x }, y{ _other.y }
	{
	}

	// Move constructor
	Vec2::Vec2(Vec2&& _other) noexcept
		: x{ _other.x }, y{ _other.y }
	{
		_other.x = 0.f;
		_other.y = 0.f;
	}

	Vec2::~Vec2() = default;

	// Adds two Vec2's
	Vec2 Vec2::Add(const Vec2& _lhs, const Vec2& _rhs)
	{
		return { _lhs.x + _rhs.x, _lhs.y + _rhs.y };
	}

	// Subtracts _rhs vector from _lhs vector
	Vec2 Vec2::Subtract(const Vec2& _lhs, const Vec2& _rhs)
	{
		return { _lhs.x - _rhs.x, _lhs.y - _rhs.y };
	}

	// Scales _lhs vector by _rhs float
	Vec2 Vec2::Scale(const Vec2& _lhs, float _rhs)
	{
		return { _lhs.x * _rhs, _lhs.y * _rhs };
	}

	// Returns normalized vector
	Vec2 Vec2::Normalised(const Vec2& _vec)
	{
		const float mag = _vec.Magnitude();

		if (Compare(mag, 0.f))
		{
			return Vec2{ 0.f, 0.f };
		}
		else
		{
			return Vec2{ _vec.x / mag, _vec.y / mag };
		}
	}

	// Returns distance between 2 vectors
	float Vec2::Distance(const Vec2& _a, const Vec2& _b)
	{
		return (_a - _b).Magnitude();
	}

	// Returns dot product 
	float Vec2::Dot(const Vec2& _lhs, const Vec2& _rhs)
	{
		return (_lhs.x * _rhs.x) + (_lhs.y * _rhs.y);
	}

	Vec2 Vec2::Lerp(const Vec2& _a, const Vec2& _b, float _t)
	{
		return {};
	}

	// Creates a Vec2 that stores a rotation 
	Vec2 Vec2::CreateRotationVector(float _radians)
	{
		return { cosf(_radians), sinf(_radians) };
	}

	// Returns dot product 
	float Vec2::Dot(const Vec2& _rhs)
	{
		return (x * _rhs.x) + (y * _rhs.y);
	}

	// Returns vectors magnitude 
	float Vec2::Magnitude() const
	{
		return sqrt((x * x) + (y * y));
	}

	// Returns vectors magnitude squared
	float Vec2::MagnitudeSqr() const
	{
		return (x * x) + (y * y);
	}

	// Normalise vector
	void Vec2::Normalise()
	{
		const float mag = Magnitude();

		if (Compare(mag, 0.f))
		{
			x = 0.f;
			y = 0.f;
		}
		else
		{
			x = x / mag;
			y = y / mag;
		}
	}

	// Returns normalized vector
	Vec2 Vec2::Normalised() const
	{
		const float mag = Magnitude();

		if (Compare(mag, 0.f))
		{
			return Vec2{ 0.f, 0.f };
		}
		else
		{
			return Vec2{ x / mag, y / mag };
		}
	}

	// Returns rotation of vector
	float Vec2::Rotation() const
	{
		return atan2f(y, x);
	}

	// Rotates vector
	void Vec2::Rotate(float _amount)
	{
		const float xRotated = x * cosf(_amount) - y * sinf(_amount);
		const float yRotated = x * sinf(_amount) - y * cosf(_amount);

		x = xRotated;
		y = yRotated;
	}

	// Rotates vector around a pivot
	void Vec2::RotateAround(const Vec2& _pivot, float _amount)
	{
		x -= _pivot.x;
		y -= _pivot.y;

		Rotate(_amount);

		x -= _pivot.x;
		y -= _pivot.y;
	}

	// Returns string representation of the vector
	string Vec2::ToString() const
	{
		return string("(") + std::to_string(x) + ", " + std::to_string(y) + string("(");
	}

	// Converts Vec2 to Vector2
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

	// Subtraction operator
	Vec2 Vec2::operator-(const Vec2& _other) const
	{
		return { x - _other.x, y - _other.y };
	}

	// Subtract _other from this vector
	Vec2& Vec2::operator-=(const Vec2& _other)
	{
		x -= _other.x;
		y -= _other.y;

		return *this;
	}

	// Addition operator
	Vec2 Vec2::operator+(const Vec2& _other) const
	{
		return { x + _other.x, y + _other.y };
	}

	// Add _other from this vector
	Vec2& Vec2::operator+=(const Vec2& _other)
	{
		x += _other.x;
		y += _other.y;

		return *this;
	}

	// Scales vector by _other
	Vec2 Vec2::operator*(float _other) const
	{
		return { x * _other, y * _other };
	}

	// Scales vector by _other
	Vec2& Vec2::operator*=(float _other)
	{
		x *= _other;
		y *= _other;

		return *this;
	}

	// Multiply operator
	Vec2 Vec2::operator*(const Vec2& _other) const
	{
		return { x * _other.x, y * _other.y };
	}


	// Multiply operator
	Vec2& Vec2::operator*=(const Vec2& _other)
	{
		x *= _other.x;
		y *= _other.y;

		return *this;
	}

	// Copy operator
	Vec2& Vec2::operator=(const Vec2& _other)
	{
		if (*this == _other)
			return *this;

		x = _other.x;
		y = _other.y;

		return *this;
	}

	// Move operator
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

	// Scales _rhs vector by _lhs scalar
	Vec2 operator*(float _lhs, const Vec2& _rhs)
	{
		return { _rhs.x * _lhs, _rhs.y * _lhs };
	}
}
