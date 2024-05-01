#include "AIE06Application.h"

#include <iostream>
#include <raylib/raylib.h>

AIE06Application::AIE06Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor },
m_playerMoveSpeed{ 100.f }, m_finishLine{ 300.f, 100.f, 200.f, 25.f }, m_lapCount{ 0 }, m_isInside{ false }
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
	m_playerPos = Vec2{ 400.f, 225.f };
	m_finishLineDir = Vec2{ 0.f, -1.f };
}

void AIE06Application::Tick(float _dt, AIE06Application* _app)
{
	m_playerMoveDir = Vec2::Normalised(
		Vec2
		{
			static_cast<float>(IsKeyDown(KEY_RIGHT)) - static_cast<float>(IsKeyDown(KEY_LEFT)),
			static_cast<float>(IsKeyDown(KEY_DOWN)) - static_cast<float>(IsKeyDown(KEY_UP))
		}
	);

	m_playerPos += m_playerMoveDir * m_playerMoveSpeed * _dt;

	const bool wasInsideLastFrame = m_isInside;
	const float exitDir = Vec2::Dot(m_playerMoveDir, m_finishLineDir);

	m_isInside = CheckCollisionPointRec(m_playerPos, m_finishLine);

	if(wasInsideLastFrame && !m_isInside)
	{
		if(exitDir > 0.f)
		{
			m_lapCount++;
		}
		else
		{
			m_lapCount--;
		}
	}


}

void AIE06Application::Render(AIE06Application* _app)
{
	DrawFinishLine();
	DrawPlayer();
	DrawUI();
}

void AIE06Application::EndPlay()
{
}

void AIE06Application::DrawUI()
{
	DrawText(string("lapcount: " + std::to_string(m_lapCount)).c_str(), 10, 10, 10, BLACK);
}

void AIE06Application::DrawPlayer()
{
	constexpr float radius = 10.f;

	DrawCircleV(m_playerPos, radius, RED);

	if(m_playerMoveDir.Magnitude() > 0.f)
	{
		const Vec2 end_PointLine = m_playerPos + m_playerMoveDir * radius;
		DrawLineEx(m_playerPos, end_PointLine, 2.f, BLACK);
	}
}

void AIE06Application::DrawFinishLine()
{
	DrawRectangleRec(m_finishLine, GRAY);

	DrawLineEx(
		Vec2{ m_finishLine.x, m_finishLine.y },
		Vec2{ m_finishLine.x + m_finishLine.width, m_finishLine.y },
		2.f,
		BLACK
	);
	DrawLineEx(
		Vec2{ m_finishLine.x + m_finishLine.width * .5f, m_finishLine.y },
		Vec2{ m_finishLine.x + m_finishLine.width * .5f, m_finishLine.y - 10 },
		2.f,
		BLACK
	);
}
