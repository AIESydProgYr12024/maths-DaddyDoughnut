#include "MathLib/Types/Colour.h"

#include "MathLib/MathFunctions.h"

namespace MathLib
{
	Colour::Colour()
		: value{ 0x000000FF }
	{
	}

	Colour::Colour(uint32_t _value)
		: value{ _value }
	{
	}

	Colour::Colour(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a)
	{
		SetRed(_r);
		SetGreen(_g);
		SetBlue(_b);
		SetAlpha(_a);
	}

	Colour::Colour(const Colour& _other)
		: value{ _other.value }
	{
	}

	Colour::Colour(Colour&& _other) noexcept
		: value{ _other.value }
	{
		_other.value = 0;
	}

	Colour::~Colour() = default;

	uint8_t Colour::Red() const
	{
		return static_cast<uint8_t>(value >> 24);
	}

	uint8_t Colour::Green() const
	{
		return static_cast<uint8_t>((value >> 16) & 0xFF);
	}

	uint8_t Colour::Blue() const
	{
		return static_cast<uint8_t>((value >> 8) & 0xFF);
	}

	uint8_t Colour::Alpha() const
	{
		return static_cast<uint8_t>(value);
	}

	void Colour::SetRed(uint8_t _r)
	{
		value = (value & 0x00FFFFFF) | (_r << 24);
	}

	void Colour::SetGreen(uint8_t _g)
	{
		value = (value & 0xFF00FFFF) | (_g << 16);
	}

	void Colour::SetBlue(uint8_t _b)
	{
		value = (value & 0xFFFF00FF) | (_b << 8);
	}

	void Colour::SetAlpha(uint8_t _a)
	{
		value = (value & 0xFFFFFF00) | _a;
	}

	uint32_t Colour::BitShift()
	{
		return ((Alpha() & 0xFF) << 24) | (((Red() >> 24) & 0xFF) << 16) | (((Green() >> 16) & 0xFF) << 8) | ((Blue() >> 8) & 0xFF);
	}

	Colour::operator Color() const
	{
		return { Red(), Green(), Blue(), Alpha() };
	}

	bool Colour::operator==(const Colour& _rhs) const
	{
		return Compare(Red(), _rhs.Red()) && Compare(Green(), _rhs.Green()) && Compare(Blue(), _rhs.Blue()) && Compare(Alpha(), _rhs.Alpha());
	}

	bool Colour::operator!=(const Colour& _rhs) const
	{
		return !(*this == _rhs);
	}

	Colour& Colour::operator=(const Colour& _other)
	{
		if (*this == _other)
			return *this;

		value = _other.value;

		return *this;
	}

	Colour& Colour::operator=(Colour&& _other) noexcept
	{
		if (*this == _other)
			return *this;

		value = _other.value;
		_other.value = 0.f;

		return *this;
	}
}
