#pragma once

#include <raylib/raylib.h>

#include "MathLib/Geometry/Rect.h"
#include "MathLib/Types/Vec2.h"

using MathLib::Vec2;
using MathLib::Rect;

class AIE20Application
{
public:
	AIE20Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE20Application();

public:
	void Run();
	void Quit();

private:
	int m_width;
	int m_height;
	const char* m_title;

	bool m_running;
	Color m_clearColor;

	Rect* m_box1;
	Rect* m_box2;

	bool m_resolveCollision;

private:
	void BeginPlay();

	void Tick(float _dt, AIE20Application* _app);
	void Render(AIE20Application* _app);

	void EndPlay();

	void DrawBox(Rect* _box, Color _color);
	void DrawBoxClosestPoint(const Rect* _box, const Vec2& _point);
	void DrawBoxIntersection(const Rect* _a, const Rect* _b);

};