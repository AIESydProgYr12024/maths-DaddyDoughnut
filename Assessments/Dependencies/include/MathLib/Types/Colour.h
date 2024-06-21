#pragma once

#include <stdint.h>

#include <raylib/raylib.h>

namespace MathLib
{
	class Colour
	{
	public:
		uint32_t value;

	public:
		Colour();
		Colour(uint32_t _value);
		Colour(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a);

		Colour(const Colour& _other);
		Colour(Colour&& _other) noexcept;

		~Colour();

	public:
		uint8_t Red() const;
		uint8_t Green() const;
		uint8_t Blue() const;
		uint8_t Alpha() const;

		void SetRed(uint8_t _r);
		void SetGreen(uint8_t _g);
		void SetBlue(uint8_t _b);
		void SetAlpha(uint8_t _a);

		uint32_t BitShift();

		public:
		operator Color() const;

		bool operator==(const Colour& _rhs) const;
		bool operator!=(const Colour& _rhs) const;

		Colour& operator=(const Colour& _other);
		Colour& operator=(Colour&& _other) noexcept;

	};
}