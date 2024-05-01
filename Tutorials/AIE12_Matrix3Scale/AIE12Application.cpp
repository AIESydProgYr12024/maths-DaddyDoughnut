#include "AIE12Application.h"

#include <raylib/raylib.h>

AIE12Application::AIE12Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
	m_matrixRenderer = new Matrix3Renderer(
		{ static_cast<float>(_width), static_cast<float>(_height) },
		{ 24.f, 24.f }
	);
}

AIE12Application::~AIE12Application()
{
	delete m_matrixRenderer;
	m_matrixRenderer = nullptr;
}

void AIE12Application::Run()
{
	InitWindow(m_width, m_height, m_title);

	BeginPlay();

	while (m_running)
	{
		Tick(GetFrameTime(), this);

		BeginDrawing();
		ClearBackground(m_clearColor);

		Render(this);

		EndDrawing();

		if (WindowShouldClose())
			m_running = false;
	}

	EndPlay();

	CloseWindow();
}

void AIE12Application::Quit()
{
	m_running = false;
}

void AIE12Application::BeginPlay()
{
}

void AIE12Application::Tick(float _dt, AIE12Application* _app)
{
	if (IsKeyPressed(KEY_W))
		m_matrix.Translate({ 0, 1 });

	if (IsKeyPressed(KEY_S))
		m_matrix.Translate({ 0, -1 });

	if (IsKeyPressed(KEY_A))
		m_matrix.Translate({ -1, 0 });

	if (IsKeyPressed(KEY_D))
		m_matrix.Translate({ 1, 0 });

	if (IsKeyPressed(KEY_UP))
		m_matrix.SetScale(m_matrix.GetScale() + MathLib::Vec2{ 0, 1 });

	if (IsKeyPressed(KEY_DOWN))
		m_matrix.SetScale(m_matrix.GetScale() + MathLib::Vec2{ 0, -1 });

	if (IsKeyPressed(KEY_LEFT))
		m_matrix.SetScale(m_matrix.GetScale() + MathLib::Vec2{ -1, 0 });

	if (IsKeyPressed(KEY_RIGHT))
		m_matrix.SetScale(m_matrix.GetScale() + MathLib::Vec2{ 1, 0 });




}

void AIE12Application::Render(AIE12Application* _app)
{
	m_matrixRenderer->BeginRender();

	m_matrixRenderer->DrawMatrix("Matrix", m_matrix, RED, { 10.f, 10.f });

	m_matrixRenderer->EndRender();
}

void AIE12Application::EndPlay()
{
}
