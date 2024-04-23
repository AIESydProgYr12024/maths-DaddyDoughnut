#include "AIE13Application.h"

#include <raylib/raylib.h>

AIE13Application::AIE13Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE13Application::~AIE13Application() = default;

void AIE13Application::Run()
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

void AIE13Application::Quit()
{
	m_running = false;
}

void AIE13Application::BeginPlay()
{
}

void AIE13Application::Tick(float _dt, AIE13Application* _app)
{
}

void AIE13Application::Render(AIE13Application* _app)
{
}

void AIE13Application::EndPlay()
{
}
