#include "MathLib/Types/Colour.h"

namespace MathLib
{
	Colour::Colour()
	{
	}

	Colour::Colour(uint32_t _value)
	{
	}

	Colour::Colour(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a)
	{
	}

	Colour::Colour(const Colour& _other)
	{
	}

	Colour::Colour(Colour&& _other) noexcept
	{
	}

	Colour::~Colour()
	{
	}

	uint8_t Colour::Red() const
	{
		return 0;
	}

	uint8_t Colour::Green() const
	{
		return 0;
	}

	uint8_t Colour::Blue() const
	{
		return 0;
	}

	uint8_t Colour::Alpha() const
	{
		return 0;
	}

	void Colour::SetRed(uint8_t _r)
	{
	}

	void Colour::SetGreen(uint8_t _g)
	{
	}

	void Colour::SetBlue(uint8_t _b)
	{
	}

	void Colour::SetAlpha(uint8_t _a)
	{
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
