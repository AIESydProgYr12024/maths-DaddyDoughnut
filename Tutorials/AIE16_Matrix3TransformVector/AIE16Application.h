#pragma once

#include <raylib/raylib.h>
#include "MathLib/Matrix3Renderer.h"

using MathLib::Vec2;
using MathLib::Mat3;
using MathLib::Matrix3Renderer;

class AIE16Application
{
public:
	AIE16Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE16Application();

public:
	void Run();
	void Quit();

private:
	int m_width;
	int m_height;
	const char* m_title;

	bool m_running;
	Color m_clearColor;

	Mat3 m_transform;
	Matrix3Renderer* m_renderer;

	Vec2 m_point1;
	Vec2 m_point2;
	Vec2 m_point3;
	Vec2 m_point4;
private:
	void BeginPlay();

	void Tick(float _dt, AIE16Application* _app);
	void Render(AIE16Application* _app);

	void EndPlay();

};