#include "AIE11Application.h"

#include <raylib/raylib.h>

AIE11Application::AIE11Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE11Application::~AIE11Application()
{
	
}

void AIE11Application::Run()
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

void AIE11Application::Quit()
{
	m_running = false;
}

void AIE11Application::BeginPlay()
{
}

void AIE11Application::Tick(float _dt, AIE11Application* _app)
{
}

void AIE11Application::Render(AIE11Application* _app)
{
}

void AIE11Application::EndPlay()
{
}
