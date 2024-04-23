#include "AIE03Application.h"

#include <raylib/raylib.h>

AIE03Application::AIE03Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE03Application::~AIE03Application() = default;

void AIE03Application::Run()
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

void AIE03Application::Quit()
{
	m_running = false;
}

void AIE03Application::BeginPlay()
{
}

void AIE03Application::Tick(float _dt, AIE03Application* _app)
{
}

void AIE03Application::Render(AIE03Application* _app)
{
}

void AIE03Application::EndPlay()
{
}
