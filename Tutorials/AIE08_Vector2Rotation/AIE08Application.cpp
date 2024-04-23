#include "AIE08Application.h"

#include <raylib/raylib.h>

AIE08Application::AIE08Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE08Application::~AIE08Application() = default;

void AIE08Application::Run()
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

void AIE08Application::Quit()
{
	m_running = false;
}

void AIE08Application::BeginPlay()
{
}

void AIE08Application::Tick(float _dt, AIE08Application* _app)
{
}

void AIE08Application::Render(AIE08Application* _app)
{
}

void AIE08Application::EndPlay()
{
}
