#include "AIE20Application.h"

#include <raylib/raylib.h>

#include "MathLib/Geometry/Hit.h"

using MathLib::Hit;

AIE20Application::AIE20Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor },
	m_box1{ new Rect({ 400.f, 400.f }, {50.f, 50.f}) }, m_box2{ new Rect({ 500.f, 400.f }, {25.f, 25.f}) },
	m_resolveCollision{ false }
{
}

AIE20Application::~AIE20Application()
{
	delete m_box1;
	m_box1 = nullptr;

	delete m_box2;
	m_box2 = nullptr;
}

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
	const Vec2 movement = 
	{

		static_cast<float>(IsKeyDown(KEY_D)) - static_cast<float>(IsKeyDown(KEY_A)),
		static_cast<float>(IsKeyDown(KEY_S)) - static_cast<float>(IsKeyDown(KEY_W))

	};

	m_box2->center += movement * 50 * _dt;

	if (IsKeyPressed(KEY_SPACE))
		m_resolveCollision = !m_resolveCollision;

	if(m_resolveCollision)
	{
		if (const Hit* hit = m_box1->Intersects(*m_box2))
		{
			m_box2->center += hit->delta;

			delete hit;
		}
	}
}

void AIE20Application::Render(AIE20Application* _app)
{
	DrawBox(m_box1, BLACK);
	DrawBoxClosestPoint(m_box1, GetMousePosition());

	DrawBox(m_box1, BLACK);
	DrawBoxIntersection(m_box1, m_box2);

}

void AIE20Application::EndPlay()
{
}

void AIE20Application::DrawBox(Rect* _box, Color _color)
{
	if (_box->Contains(GetMousePosition()))
		_color = RED;

	DrawRectangleLinesEx(*_box, 1.f, _color);
}

void AIE20Application::DrawBoxClosestPoint(const Rect* _box, const Vec2& _point)
{
	if(const Hit* hit = _box->Intersects(_point))
	{
		DrawLineEx(hit->point, hit->point + hit->normal * 15.f, 2.f, RED);
		DrawCircleV(hit->point, 3.f, RED);

		delete hit;
	}
}

void AIE20Application::DrawBoxIntersection(const Rect* _a, const Rect* _b)
{
}
