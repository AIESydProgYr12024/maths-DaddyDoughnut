#include "AIE02Application.h"

#include <raylib/raylib.h>

#include "MathLib/Types/Vec2.h"

AIE02Application::AIE02Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
}

AIE02Application::~AIE02Application() = default;

void AIE02Application::Run()
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

void AIE02Application::Quit()
{
	m_running = false;
}

void AIE02Application::BeginPlay()
{
	m_playerPos = MathLib::Vec2{ static_cast<float>(m_width) * .5f,static_cast<float>(m_height) * .5f };
}

void AIE02Application::Tick(float _dt, AIE02Application* _app)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		m_playerPos = GetMousePosition();
	}

	constexpr float speed = 10.f;
	const MathLib::Vec2 right = speed * MathLib::Vec2{ 1, 0 };
	const MathLib::Vec2 down = MathLib::Vec2{ 0, 1 } * speed;

	if(IsKeyPressed(KEY_RIGHT))
	{
		m_playerPos = MathLib::Vec2::Add(m_playerPos, right);
	}
	if (IsKeyPressed(KEY_LEFT))
	{
		m_playerPos = MathLib::Vec2::Subtract(m_playerPos, right);
	}

	if (IsKeyPressed(KEY_UP))
	{
		m_playerPos -= down;
	}
	if (IsKeyPressed(KEY_DOWN))
	{
		m_playerPos += down;
	}
}

void AIE02Application::Render(AIE02Application* _app)
{
	DrawCircleV(m_playerPos, 3.f, BLACK);
}

void AIE02Application::EndPlay()
{
}
