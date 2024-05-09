#include "AIE19Application.h"

#include <functional>
#include <raylib/raylib.h>

#include "MathLib/Geometry/Hit.h"

using MathLib::Hit;

AIE19Application::AIE19Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor },
	m_circle1{ new Circle(Vec2{ 400.f, 225.f }, 50.f) }, m_circle2{ new Circle(Vec2{ 500.f, 225.f }, 20.f) },
	m_resolveCollision{ false }
{
}

AIE19Application::~AIE19Application()
{
	delete m_circle1;
	m_circle1 = nullptr;

	delete m_circle2;
	m_circle2 = nullptr;
};

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
	const Vec2 movement = 
	{

		static_cast<float>(IsKeyDown(KEY_D)) - static_cast<float>(IsKeyDown(KEY_A)),
		static_cast<float>(IsKeyDown(KEY_S)) - static_cast<float>(IsKeyDown(KEY_W))

	};

	m_circle2->center += movement * 50 * _dt;

	if (IsKeyPressed(KEY_SPACE))
		m_resolveCollision = !m_resolveCollision;

	if(m_resolveCollision)
	{
		if (const Hit* hit = m_circle1->Intersects(*m_circle2))
		{
			m_circle2->center += hit->delta;

			delete hit;
		}
	}
}

void AIE19Application::Render(AIE19Application* _app)
{
	DrawCircle(m_circle1, BLACK);
	DrawClosestPoint(m_circle1, GetMousePosition());

	DrawCircle(m_circle2, BLACK);
	DrawCircleIntersection(m_circle1, m_circle2);

	
}

void AIE19Application::EndPlay()
{
}

void AIE19Application::DrawCircle(const Circle* _circle, Color _color)
{
	DrawCircleLinesV(_circle->center, _circle->radius, _color);
}

void AIE19Application::DrawClosestPoint(const Circle* _circle, const Vec2& _point)
{
	if (const Hit* hit = _circle->Intersects(_point))
	{
		DrawLineEx(hit->point, hit->point + hit->normal * 15.f, 2.f, RED);
		DrawCircleV(hit->point, 3.f, RED);

		delete hit;
	}
}

void AIE19Application::DrawCircleIntersection(const Circle* _a, const Circle* _b)
{
	if(const Hit* hit = _a->Intersects(*_b))
	{
		const Circle c = { _b->center + hit->delta, _b->radius };
		DrawCircle(&c, RED);
		DrawLineEx(hit->point, hit->point + hit->normal * 15.f, 2.f, RED);
	}
}
