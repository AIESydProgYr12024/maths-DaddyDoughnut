#include "AIE16Application.h"

#include <raylib/raylib.h>

AIE16Application::AIE16Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor },
m_transform{ 1.f }
{
	m_renderer = new Matrix3Renderer(
		{ static_cast<float>(_width), static_cast<float>(_height) },
		{ 24.f, 24.f }
	);
}

AIE16Application::~AIE16Application()
{
	delete m_renderer;
	m_renderer = nullptr;
}

void AIE16Application::Run()
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

void AIE16Application::Quit()
{
	m_running = false;
}

void AIE16Application::BeginPlay()
{
	m_transform = Mat3::CreateZRotation(45.f * DEG2RAD);

	m_point1 = Vec2::zero;
	m_point2 = Vec2::right * 2.f;
	m_point3 = Vec2::up * 2.f;
	m_point4 = Vec2::one * 2.f;
}

void AIE16Application::Tick(float _dt, AIE16Application* _app)
{
	const float rot = 90.f * _dt * DEG2RAD;

	if (IsKeyDown(KEY_Q))
		m_transform = Mat3::CreateZRotation(rot) * m_transform;

	if (IsKeyDown(KEY_E))
		m_transform = Mat3::CreateZRotation(-rot) * m_transform;

	if (IsKeyDown(KEY_W))
		m_transform = Mat3::CreateTranslation(Vec2::up * _dt * 10.f) * m_transform;

	if (IsKeyDown(KEY_S))
		m_transform = Mat3::CreateTranslation(Vec2::down * _dt * 10.f) * m_transform;

	if (IsKeyDown(KEY_A))
		m_transform = Mat3::CreateTranslation(Vec2::right * _dt * -10.f) * m_transform;

	if (IsKeyDown(KEY_D))
		m_transform = Mat3::CreateTranslation(Vec2::left * _dt * -10.f) * m_transform;
}

void AIE16Application::Render(AIE16Application* _app)
{
	const Vec2 transformedP1 = m_transform.TransformPoint(m_point1);
	const Vec2 transformedP2 = m_transform.TransformPoint(m_point2);
	const Vec2 transformedP3 = m_transform.TransformPoint(m_point3);
	const Vec2 transformedP4 = m_transform.TransformPoint(m_point4);

	m_renderer->BeginRender();

	m_renderer->DrawMatrix("Actor", m_transform, RED, { 10.f, 10.f });

	m_renderer->DrawPoint(m_point1, BLACK, 5.f);
	m_renderer->DrawPoint(m_point2, BLACK, 5.f);
	m_renderer->DrawPoint(m_point3, BLACK, 5.f);
	m_renderer->DrawPoint(m_point4, BLACK, 5.f);

	m_renderer->DrawPoint(transformedP1, BLUE, 5.f);
	m_renderer->DrawPoint(transformedP2, BLUE, 5.f);
	m_renderer->DrawPoint(transformedP3, BLUE, 5.f);
	m_renderer->DrawPoint(transformedP4, BLUE, 5.f);

	m_renderer->EndRender();

	m_transform = m_renderer->GetMatrix("Actor");
}

void AIE16Application::EndPlay()
{
}
