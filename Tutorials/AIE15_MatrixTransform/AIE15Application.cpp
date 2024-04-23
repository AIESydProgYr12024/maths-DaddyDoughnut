#include "AIE15Application.h"

#include <raylib/raylib.h>

AIE15Application::AIE15Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE15Application::~AIE15Application() = default;

void AIE15Application::Run()
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

void AIE15Application::Quit()
{
	m_running = false;
}

void AIE15Application::BeginPlay()
{
}

void AIE15Application::Tick(float _dt, AIE15Application* _app)
{
}

void AIE15Application::Render(AIE15Application* _app)
{
}

void AIE15Application::EndPlay()
{
}
