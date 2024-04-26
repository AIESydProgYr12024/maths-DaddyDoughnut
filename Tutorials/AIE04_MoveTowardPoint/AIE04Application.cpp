#include "AIE04Application.h"

#include <raylib/raylib.h>

AIE04Application::AIE04Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE04Application::~AIE04Application() = default;

void AIE04Application::Run()
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

void AIE04Application::Quit()
{
	m_running = false;
}

void AIE04Application::BeginPlay()
{
	m_playerPos = Vec2{ 400.f, 255.f };
	m_TargetPos = Vec2{ 500.f, 255.f };
}

void AIE04Application::Tick(float _dt, AIE04Application* _app)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		m_TargetPos = GetMousePosition();

	const Vec2 toTargetPos = Vec2::Normalised(m_TargetPos - m_playerPos);
	m_playerPos += toTargetPos * _dt * 100.f;
}

void AIE04Application::Render(AIE04Application* _app)
{
	DrawPlayer();
	DrawTarget();
}

void AIE04Application::EndPlay()
{
}

void AIE04Application::DrawPlayer()
{
	constexpr float radius = 10.f;

	DrawCircleV(m_playerPos, radius, RED);

	const Vec2 endPointLine = m_playerPos + Vec2::Normalised(m_TargetPos - m_playerPos) * radius;
	DrawLineEx(m_playerPos, endPointLine, 2.f, BLACK);

}

void AIE04Application::DrawTarget()
{
	DrawCircleV(m_TargetPos, 3.f, BLACK);
}


