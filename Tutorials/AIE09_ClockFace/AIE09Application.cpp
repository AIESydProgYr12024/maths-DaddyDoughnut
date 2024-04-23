#include "AIE09Application.h"

#include <raylib/raylib.h>

AIE09Application::AIE09Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE09Application::~AIE09Application() = default;

void AIE09Application::Run()
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

void AIE09Application::Quit()
{
	m_running = false;
}

void AIE09Application::BeginPlay()
{
}

void AIE09Application::Tick(float _dt, AIE09Application* _app)
{
}

void AIE09Application::Render(AIE09Application* _app)
{
}

void AIE09Application::EndPlay()
{
}
