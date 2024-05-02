#include "AIE14Application.h"

#include <raylib/raylib.h>

MatrixMultiplyPair::MatrixMultiplyPair(const char* _label, Mat3 _a, Mat3 _b)
	: label{ _label }, a{ std::move(_a) }, b{ std::move(_b) }
{
}

AIE14Application::AIE14Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor },
m_matrixA{ 1.f }, m_matrixB{ 1.f }, m_matrixC{ 1.f }, m_currentIndex{ 0 }
{
	m_renderer = new Matrix3Renderer(
		{ static_cast<float>(_width), static_cast<float>(_height) },
		{ 24.f, 24.f }
	);
}

AIE14Application::~AIE14Application()
{
	delete m_renderer;
	m_renderer = nullptr;

	for (const auto& pair : m_pairs)
		delete pair;

	m_pairs.clear();
}

void AIE14Application::Run()
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

void AIE14Application::Quit()
{
	m_running = false;
}

void AIE14Application::BeginPlay()
{
	PopulateMatrixPairs();
	UpdateSelectedMatrix();
}

void AIE14Application::Tick(float _dt, AIE14Application* _app)
{
}

void AIE14Application::Render(AIE14Application* _app)
{
	m_renderer->BeginRender();

	m_renderer->DrawMatrix("Matrix A", m_matrixA, RED, Vec2{ 10, 140 });
	m_renderer->DrawMatrix("Matrix B", m_matrixB, GREEN, Vec2{ 140, 10 });
	m_renderer->DrawMatrix("Matrix C", m_matrixC, BLUE, Vec2{ 10, 10 });

	m_matrixA = m_renderer->GetMatrix("Matrix A");
	m_matrixB = m_renderer->GetMatrix("Matrix B");

	m_renderer->EndRender();

	DrawRectangle(140, 140, 120, 20 + static_cast<int>(m_pairs.size()) * 15, WHITE);
	DrawRectangleLines(140, 140, 120, 20 + static_cast<int>(m_pairs.size()) * 15, DARKGRAY);
	DrawText("Space to swap A & B", 145, 145, 10, DARKGRAY);

	for(int i = 0; i < static_cast<int>(m_pairs.size()); ++i)
	{
		if (i == m_currentIndex)
			DrawRectangle(142, 160 + i * 15, 116, 13, LIGHTGRAY);

		const MatrixMultiplyPair* pair = m_pairs[i];
		DrawText(pair->label, 145, 162 + i * 15, 10, DARKGRAY);
	}
}

void AIE14Application::EndPlay()
{
}

void AIE14Application::Swap(Mat3& _a, Mat3& _b) const
{
	const Mat3 tmp = _a;
	_a = _b;
	_b = tmp;
}

void AIE14Application::UpdateSelectedMatrix()
{
	if (m_pairs.empty())
		return;

	m_matrixA = m_pairs[m_currentIndex % m_pairs.size()]->a;
	m_matrixB = m_pairs[m_currentIndex % m_pairs.size()]->b;
}

void AIE14Application::PopulateMatrixPairs()
{
}
