#include "AIE12Application.h"

#include <raylib/raylib.h>

AIE12Application::AIE12Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE12Application::~AIE12Application() = default;

void AIE12Application::Run()
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

void AIE12Application::Quit()
{
	m_running = false;
}

void AIE12Application::BeginPlay()
{
}

void AIE12Application::Tick(float _dt, AIE12Application* _app)
{
}

void AIE12Application::Render(AIE12Application* _app)
{
}

void AIE12Application::EndPlay()
{
}
