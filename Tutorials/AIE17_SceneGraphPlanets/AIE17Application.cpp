#include "AIE17Application.h"

#include <raylib/raylib.h>

AIE17Application::AIE17Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE17Application::~AIE17Application() = default;

void AIE17Application::Run()
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

void AIE17Application::Quit()
{
	m_running = false;
}

void AIE17Application::BeginPlay()
{
}

void AIE17Application::Tick(float _dt, AIE17Application* _app)
{
}

void AIE17Application::Render(AIE17Application* _app)
{
}

void AIE17Application::EndPlay()
{
}
