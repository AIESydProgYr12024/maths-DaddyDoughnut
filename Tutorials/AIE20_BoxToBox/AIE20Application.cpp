#include "AIE20Application.h"

#include <raylib/raylib.h>

AIE20Application::AIE20Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE20Application::~AIE20Application() = default;

void AIE20Application::Run()
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

void AIE20Application::Quit()
{
	m_running = false;
}

void AIE20Application::BeginPlay()
{
}

void AIE20Application::Tick(float _dt, AIE20Application* _app)
{
}

void AIE20Application::Render(AIE20Application* _app)
{
}

void AIE20Application::EndPlay()
{
}
