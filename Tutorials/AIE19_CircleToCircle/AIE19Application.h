#pragma once

#include <raylib/raylib.h>

#include "MathLib/Geometry/Circle.h"
#include "MathLib/Types/Vec2.h"

using MathLib::Vec2;
using MathLib::Circle;

class AIE19Application
{
public:
	AIE19Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE19Application();

public:
	void Run();
	void Quit();

private:
	int m_width;
	int m_height;
	const char* m_title;

	bool m_running;
	Color m_clearColor;

	Circle* m_circle1;
	Circle* m_circle2;

	bool m_resolveCollision;

private:
	void BeginPlay();

	void Tick(float _dt, AIE19Application* _app);
	void Render(AIE19Application* _app);

	void EndPlay();

	void DrawCircle(const Circle* _circle, Color _color);
	void DrawClosestPoint(const Circle* _circle, const Vec2& _point);

	void DrawCircleIntersection(const Circle* _a, const Circle* _b);

};