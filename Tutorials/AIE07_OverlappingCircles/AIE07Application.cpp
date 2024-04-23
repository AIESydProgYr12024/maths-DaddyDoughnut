#include "AIE07Application.h"

#include <raylib/raylib.h>

AIE07Application::AIE07Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE07Application::~AIE07Application()
{
	
}

void AIE07Application::Run()
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

void AIE07Application::Quit()
{
	m_running = false;
}

void AIE07Application::BeginPlay()
{
}

void AIE07Application::Tick(float _dt, AIE07Application* _app)
{
}

void AIE07Application::Render(AIE07Application* _app)
{
}

void AIE07Application::EndPlay()
{
}
