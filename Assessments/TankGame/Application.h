#pragma once

#include <raylib/raylib.h>

class Application
{
public:
	Application(int _width, int _height, const char* _title, Color _clrColor);
	~Application();

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

	void Tick(float _dt, Application* _app);
	void Render(Application* _app);

	void EndPlay();

};