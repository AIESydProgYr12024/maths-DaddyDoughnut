#include "AIE19Application.h"

#include <raylib/raylib.h>

AIE19Application::AIE19Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE19Application::~AIE19Application() = default;

void AIE19Application::Run()
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

void AIE19Application::Quit()
{
	m_running = false;
}

void AIE19Application::BeginPlay()
{
}

void AIE19Application::Tick(float _dt, AIE19Application* _app)
{
}

void AIE19Application::Render(AIE19Application* _app)
{
}

void AIE19Application::EndPlay()
{
}
