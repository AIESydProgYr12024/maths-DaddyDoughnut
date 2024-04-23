#include "AIE04Application.h"

#include <raylib/raylib.h>

AIE04Application::AIE04Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE04Application::~AIE04Application() = default;

void AIE04Application::Run()
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

void AIE04Application::Quit()
{
	m_running = false;
}

void AIE04Application::BeginPlay()
{
}

void AIE04Application::Tick(float _dt, AIE04Application* _app)
{
}

void AIE04Application::Render(AIE04Application* _app)
{
}

void AIE04Application::EndPlay()
{
}
