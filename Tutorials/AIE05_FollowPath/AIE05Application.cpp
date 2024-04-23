#include "AIE05Application.h"

#include <raylib/raylib.h>

AIE05Application::AIE05Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE05Application::~AIE05Application() = default;

void AIE05Application::Run()
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

void AIE05Application::Quit()
{
	m_running = false;
}

void AIE05Application::BeginPlay()
{
}

void AIE05Application::Tick(float _dt, AIE05Application* _app)
{
}

void AIE05Application::Render(AIE05Application* _app)
{
}

void AIE05Application::EndPlay()
{
}
