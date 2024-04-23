#pragma once

#include <raylib/raylib.h>

class AIE20Application
{
public:
	AIE20Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE20Application();

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

	void Tick(float _dt, AIE20Application* _app);
	void Render(AIE20Application* _app);

	void EndPlay();

};