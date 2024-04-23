#pragma once

#include <raylib/raylib.h>

class AIE04Application
{
public:
	AIE04Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE04Application();

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

	void Tick(float _dt, AIE04Application* _app);
	void Render(AIE04Application* _app);

	void EndPlay();

};