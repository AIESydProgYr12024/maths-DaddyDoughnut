#pragma once

#include <raylib/raylib.h>
#include <vector>
#include "MathLib/Types/Vec2.h"

using std::vector;
using MathLib::Vec2;


class AIE05Application
{
public:
	AIE05Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE05Application();

public:
	void Run();
	void Quit();

private:
	int m_width;
	int m_height;
	const char* m_title;

	bool m_running;
	Color m_clearColor;

	vector<Vec2> m_path;

	Vec2 m_playerPos;

private:
	void BeginPlay();

	void Tick(float _dt, AIE05Application* _app);
	void Render(AIE05Application* _app);

	void EndPlay();

	void DrawPlayer();
	void DrawPath();

};