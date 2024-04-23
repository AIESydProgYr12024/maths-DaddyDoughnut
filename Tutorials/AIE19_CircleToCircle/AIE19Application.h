#pragma once

#include <raylib/raylib.h>

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

private:
	void BeginPlay();

	void Tick(float _dt, AIE19Application* _app);
	void Render(AIE19Application* _app);

	void EndPlay();

};