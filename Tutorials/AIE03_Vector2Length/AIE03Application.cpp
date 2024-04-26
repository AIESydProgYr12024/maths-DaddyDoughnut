#include "AIE03Application.h"

#include <raylib/raylib.h>

AIE03Application::AIE03Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE03Application::~AIE03Application() = default;

void AIE03Application::Run()
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

void AIE03Application::Quit()
{
	m_running = false;
}

void AIE03Application::BeginPlay()
{
}

void AIE03Application::Tick(float _dt, AIE03Application* _app)
{
	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		m_points.emplace_back(GetMousePosition());

		m_totalLength = 0;
		for (size_t i = 1; i < m_points.size(); ++i)
		{
			m_totalLength += (m_points[i] - m_points[i - 1]).Magnitude();
		}
	}
}

void AIE03Application::Render(AIE03Application* _app)
{
	for (size_t i = 1; i < m_points.size(); ++i)
	{
		DrawLineV(m_points[i], m_points[i - 1], BLACK);
	}

	for(auto& p : m_points)
	{
		DrawCircleV(p, 3.f, BLACK);
	}
}


void AIE03Application::EndPlay()
{
}
