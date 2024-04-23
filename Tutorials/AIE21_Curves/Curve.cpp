#include "Curve.h"

Curve::Curve(const char* _title, const CurveFnc _fnc)
	: m_title{ _title }, m_fnc{ _fnc }
{
}

float Curve::Run(const float _t, const float _start, const float _end) const
{
	return m_fnc(_t, _start, _end);
}

const char* Curve::GetTitle() const
{
	return m_title;
}
