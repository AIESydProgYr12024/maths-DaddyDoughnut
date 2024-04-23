#pragma once

#include <raylib/raylib.h>

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

private:
	void BeginPlay();

	void Tick(float _dt, AIE16Application* _app);
	void Render(AIE16Application* _app);

	void EndPlay();

};