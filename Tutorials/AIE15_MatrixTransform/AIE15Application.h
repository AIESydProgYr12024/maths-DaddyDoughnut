#pragma once

#include <raylib/raylib.h>

#include "MathLib/Matrix3Renderer.h"

using MathLib::Vec2;
using MathLib::Mat3;
using MathLib::Matrix3Renderer;

class AIE15Application
{
public:
	AIE15Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE15Application();

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

private:
	void BeginPlay();

	void Tick(float _dt, AIE15Application* _app);
	void Render(AIE15Application* _app);

	void EndPlay();

};