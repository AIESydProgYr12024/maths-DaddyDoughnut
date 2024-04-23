#pragma once

#include <raylib/raylib.h>

class AIE09Application
{
public:
	AIE09Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE09Application();

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

	void Tick(float _dt, AIE09Application* _app);
	void Render(AIE09Application* _app);

	void EndPlay();

};