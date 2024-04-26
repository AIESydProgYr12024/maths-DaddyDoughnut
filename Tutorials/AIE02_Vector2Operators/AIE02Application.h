#pragma once

#include <raylib/raylib.h>
#include "MathLib/Types/Vec2.h"
#include <vector>
using std::vector;
using MathLib::Vec2;


class AIE02Application
{
public:
	AIE02Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE02Application();

public:
	void Run();
	void Quit();

private:
	int m_width;
	int m_height;
	const char* m_title;

	bool m_running;
	Color m_clearColor;

	
	Vec2 m_playerPos;
private:
	void BeginPlay();

	void Tick(float _dt, AIE02Application* _app);
	void Render(AIE02Application* _app);

	void EndPlay();

};
