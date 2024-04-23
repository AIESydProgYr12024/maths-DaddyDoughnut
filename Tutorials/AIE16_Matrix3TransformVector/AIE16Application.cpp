#include "AIE16Application.h"

#include <raylib/raylib.h>

AIE16Application::AIE16Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE16Application::~AIE16Application() = default;

void AIE16Application::Run()
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

void AIE16Application::Quit()
{
	m_running = false;
}

void AIE16Application::BeginPlay()
{
}

void AIE16Application::Tick(float _dt, AIE16Application* _app)
{
}

void AIE16Application::Render(AIE16Application* _app)
{
}

void AIE16Application::EndPlay()
{
}
