#include "AIE11Application.h"

#include <raylib/raylib.h>

AIE11Application::AIE11Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
	m_matrixRenderer = new Matrix3Renderer(
		{ static_cast<float>(_width), static_cast<float>(_height) },
		{ 24.f, 24.f }
	);
}

AIE11Application::~AIE11Application()
{
	delete m_matrixRenderer;
	m_matrixRenderer = nullptr;
}

void AIE11Application::Run()
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

void AIE11Application::Quit()
{
	m_running = false;
}

void AIE11Application::BeginPlay()
{
}

void AIE11Application::Tick(float _dt, AIE11Application* _app)
{
	if (IsKeyPressed(KEY_W))
		m_matrix.Translate({ 0, 1 });

	if (IsKeyPressed(KEY_S))
		m_matrix.Translate({ 0, -1 });

	if (IsKeyPressed(KEY_A))
		m_matrix.Translate({ -1, 0 });

	if (IsKeyPressed(KEY_D))
		m_matrix.Translate({ 1, 0 });
}

void AIE11Application::Render(AIE11Application* _app)
{
	m_matrixRenderer->BeginRender();

	m_matrixRenderer->DrawMatrix("Matrix", m_matrix, RED, { 10.f, 10.f });

	m_matrixRenderer->EndRender();
}

void AIE11Application::EndPlay()
{
}
