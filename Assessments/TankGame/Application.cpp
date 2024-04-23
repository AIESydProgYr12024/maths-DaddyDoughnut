#include "Application.h"

#include <raylib/raylib.h>

Application::Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

Application::~Application()
{
	
}

void Application::Run()
{
	InitWindow(m_width, m_height, m_title);

	BeginPlay();

	while(m_running)
	{
		Tick(GetFrameTime(), this);

		BeginDrawing();
		ClearBackground(m_clearColor);

		Render(this);

		EndDrawing();

		if(WindowShouldClose())
			m_running = false;
	}

	EndPlay();

	CloseWindow();
}

void Application::Quit()
{
	m_running = false;
}

void Application::BeginPlay()
{
}

void Application::Tick(float _dt, Application* _app)
{
}

void Application::Render(Application* _app)
{
}

void Application::EndPlay()
{
}
