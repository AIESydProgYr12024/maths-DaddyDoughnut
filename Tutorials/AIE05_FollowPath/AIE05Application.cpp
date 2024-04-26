#include "AIE05Application.h"

#include <raylib/raylib.h>

AIE05Application::AIE05Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE05Application::~AIE05Application() = default;

void AIE05Application::Run()
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

void AIE05Application::Quit()
{
	m_running = false;
}

void AIE05Application::BeginPlay()
{
	m_playerPos = Vec2{ 400.f, 225.f };
}

void AIE05Application::Tick(float _dt, AIE05Application* _app)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		m_path.emplace_back(GetMousePosition());
	if(!m_path.empty())
	{
		const Vec2 toTargetPos = Vec2::Normalised(m_path[0] - m_playerPos);
		m_playerPos += toTargetPos * _dt * 1000.f;

		if (Vec2::Distance(m_path[0], m_playerPos) < 1.f)
			m_path.erase(m_path.begin());
	}
}

void AIE05Application::Render(AIE05Application* _app)
{
	DrawPlayer();
	DrawPath();
}

void AIE05Application::EndPlay()
{
}

void AIE05Application::DrawPlayer()
{
	constexpr float radius = 10.f;

	DrawCircleV(m_playerPos, radius, RED);

	if(!m_path.empty())
	{
		const Vec2 endPointLine = m_playerPos + Vec2::Normalised(m_path[0] - m_playerPos) * radius;
		DrawLineEx(m_playerPos, endPointLine, 2.f, BLACK);
	}
}

void AIE05Application::DrawPath()
{
	for(size_t i = 1; i < m_path.size(); ++i)
		DrawLineV(m_path[i], m_path[i - 1], BLACK);
	
	for (const auto& p : m_path)
		DrawCircleV(p, 3.f, BLACK);
}
