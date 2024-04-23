#pragma once

#include <raylib/raylib.h>

class AIE14Application
{
public:
	AIE14Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE14Application();

public:
	void Run();
	void Quit();

private:
	int m_width;
	int m_height;
	const char* m_title;

	bool m_running;
	Color m_clearColor;

private:
	void BeginPlay();

	void Tick(float _dt, AIE14Application* _app);
	void Render(AIE14Application* _app);

	void EndPlay();

};