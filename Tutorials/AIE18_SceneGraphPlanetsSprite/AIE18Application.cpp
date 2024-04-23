#include "AIE18Application.h"

#include <raylib/raylib.h>

AIE18Application::AIE18Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE18Application::~AIE18Application() = default;

void AIE18Application::Run()
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

void AIE18Application::Quit()
{
	m_running = false;
}

void AIE18Application::BeginPlay()
{
}

void AIE18Application::Tick(float _dt, AIE18Application* _app)
{
}

void AIE18Application::Render(AIE18Application* _app)
{
}

void AIE18Application::EndPlay()
{
}
