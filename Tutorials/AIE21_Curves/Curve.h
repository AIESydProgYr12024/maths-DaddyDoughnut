#pragma once

enum ECurveType
{
	LinearInterpolation,

	QuadraticEaseOut,
	QuadraticEaseIn,
	QuadraticEaseInOut,

	CubicEaseOut,
	CubicEaseIn,
	CubicEaseInOut,

	QuarticEaseOut,
	QuarticEaseIn,
	QuarticEaseInOut,

	QuinticEaseOut,
	QuinticEaseIn,
	QuinticEaseInOut,

	SinusoidaleEaseOut,
	SinusoidaleEaseIn,
	SinusoidaleEaseInOut,

	ExponentialEaseOut,
	ExponentialEaseIn,
	ExponentialEaseInOut,

	CircularEaseOut,
	CircularEaseIn,
	CircularEaseInOut,

	CurveTypeCount
};

class Curve
{
public:
	typedef float(*CurveFnc)(float _t, float _start, float _end);

public:
	Curve(const char* _title, CurveFnc _fnc);

public:
	float Run(float _t, float _start, float _end) const;

	const char* GetTitle() const;

private:
	const char* m_title;
	CurveFnc m_fnc;

};