#include "AIE02Application.h"

#include <raylib/raylib.h>

AIE02Application::AIE02Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE02Application::~AIE02Application() = default;

void AIE02Application::Run()
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

void AIE02Application::Quit()
{
	m_running = false;
}

void AIE02Application::BeginPlay()
{
}

void AIE02Application::Tick(float _dt, AIE02Application* _app)
{
}

void AIE02Application::Render(AIE02Application* _app)
{
}

void AIE02Application::EndPlay()
{
}
