#include "AIE10Application.h"

#include <raylib/raylib.h>

AIE10Application::AIE10Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor }
{
	m_matrixRenderer = new Matrix3Renderer(
		{ static_cast<float>(_width), static_cast<float>(_height) },
		{ 24.f, 24.f }
	);
}

AIE10Application::~AIE10Application()
{
	delete m_matrixRenderer;
	m_matrixRenderer = nullptr;
}

void AIE10Application::Run()
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

void AIE10Application::Quit()
{
	m_running = false;
}

void AIE10Application::BeginPlay()
{
}

void AIE10Application::Tick(float _dt, AIE10Application* _app)
{
}

void AIE10Application::Render(AIE10Application* _app)
{
	m_matrixRenderer->BeginRender();

	m_matrixRenderer->DrawMatrix("Matrix", m_matrix, RED, { 10.f, 10.f });

	m_matrixRenderer->EndRender();
}

void AIE10Application::EndPlay()
{
}
