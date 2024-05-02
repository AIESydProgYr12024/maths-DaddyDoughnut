#include "AIE15Application.h"

#include <raylib/raylib.h>

AIE15Application::AIE15Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor },
m_transform{ 1.f}
{
	m_renderer = new Matrix3Renderer(
		{ static_cast<float>(_width), static_cast<float>(_height) },
		{ 24.f, 24.f }
	);
}

AIE15Application::~AIE15Application()
{
	delete m_renderer;
	m_renderer = nullptr;
}

void AIE15Application::Run()
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

void AIE15Application::Quit()
{
	m_running = false;
}

void AIE15Application::BeginPlay()
{
}

void AIE15Application::Tick(float _dt, AIE15Application* _app)
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

void AIE15Application::Render(AIE15Application* _app)
{
	m_renderer->BeginRender();

	m_renderer->DrawMatrix("Actor", m_transform, RED, { 10.f, 10.f });

	m_renderer->EndRender();

	m_transform = m_renderer->GetMatrix("Actor");
}

void AIE15Application::EndPlay()
{
}
