#include "MathLib/Types/Colour.h"

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
		return static_cast<uint8_t>(value);
	}

	uint8_t Colour::Green() const
	{
		return static_cast<uint8_t>(value);
	}

	uint8_t Colour::Blue() const
	{
		return static_cast<uint8_t>(value);
	}

	uint8_t Colour::Alpha() const
	{
		return static_cast<uint8_t>(value);
	}

	void Colour::SetRed(uint8_t _r)
	{
		value = (value & 0x00FFFFFF) | _r;
	}

	void Colour::SetGreen(uint8_t _g)
	{
		value = (value & 0xFF00FFFF) | _g;
	}

	void Colour::SetBlue(uint8_t _b)
	{
		value = (value & 0xFFFF00FF) | _b;
	}

	void Colour::SetAlpha(uint8_t _a)
	{
		value = (value & 0xFFFFFF00) | _a;
	}

	uint32_t Colour::BitShift(uint8_t _value)
	{
		return _value >> 8;
	}

	Colour::operator Color() const
	{
		return {};
	}

	bool Colour::operator==(const Colour& _rhs) const
	{
		return false;
	}

	bool Colour::operator!=(const Colour& _rhs) const
	{
		return false;
	}

	Colour& Colour::operator=(const Colour& _other)
	{
		return *this;
	}

	Colour& Colour::operator=(Colour&& _other) noexcept
	{
		return *this;
	}
}
