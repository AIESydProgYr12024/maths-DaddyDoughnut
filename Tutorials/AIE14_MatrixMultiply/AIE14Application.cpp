#include "AIE14Application.h"

#include <raylib/raylib.h>

AIE14Application::AIE14Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE14Application::~AIE14Application() = default;

void AIE14Application::Run()
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

void AIE14Application::Quit()
{
	m_running = false;
}

void AIE14Application::BeginPlay()
{
}

void AIE14Application::Tick(float _dt, AIE14Application* _app)
{
}

void AIE14Application::Render(AIE14Application* _app)
{
}

void AIE14Application::EndPlay()
{
}
