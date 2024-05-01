#pragma once

#include <raylib/raylib.h>
#include "MathLib/Matrix3Renderer.h"

using MathLib::Mat3;
using MathLib::Matrix3Renderer;

class AIE12Application
{
public:
	AIE12Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE12Application();

public:
	void Run();
	void Quit();

private:
	int m_width;
	int m_height;
	const char* m_title;

	bool m_running;
	Color m_clearColor;

	Mat3 m_matrix;
	Matrix3Renderer* m_matrixRenderer;
private:
	void BeginPlay();

	void Tick(float _dt, AIE12Application* _app);
	void Render(AIE12Application* _app);

	void EndPlay();

};