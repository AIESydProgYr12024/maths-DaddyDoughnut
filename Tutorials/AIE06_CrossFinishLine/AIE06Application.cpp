#include "AIE06Application.h"

#include <raylib/raylib.h>

AIE06Application::AIE06Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE06Application::~AIE06Application()
{
	
}

void AIE06Application::Run()
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

void AIE06Application::Quit()
{
	m_running = false;
}

void AIE06Application::BeginPlay()
{
}

void AIE06Application::Tick(float _dt, AIE06Application* _app)
{
}

void AIE06Application::Render(AIE06Application* _app)
{
}

void AIE06Application::EndPlay()
{
}
