#include "AIE21Application.h"

#include <ranges>
#include <raylib/raylib.h>

#include "CurveFunctions.h"

#define X_DIV 19
#define Y_DIV 19
constexpr float LINE_DENSITY = 100.f;

AIE21Application::AIE21Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor },
	m_currentCurve{ 0 }, m_rect{ static_cast<float>(_width) * .5f, 40, 342, 342 }, m_t{ 0 }
{
}

AIE21Application::~AIE21Application()
{
	for (const auto& curve : m_curves | std::views::values)
		delete curve;

	m_curves.clear();
}

void AIE21Application::Run()
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

void AIE21Application::Quit()
{
	m_running = false;
}

void AIE21Application::BeginPlay()
{
	MakeCurve(LinearInterpolation, "Linear Interpolation", &LinearInterpolationFnc);
	MakeCurve(QuadraticEaseOut, "Quadratic Ease Out", &QuadraticEaseOutFnc);
	MakeCurve(QuadraticEaseIn, "Quadratic Ease In", &QuadraticEaseInFnc);
	MakeCurve(QuadraticEaseInOut, "Quadratic Ease In-Out", &QuadraticEaseInOutFnc);
	MakeCurve(CubicEaseOut, "Cubic Ease Out", &CubicEaseOutFnc);
	MakeCurve(CubicEaseIn, "Cubic Ease In", &CubicEaseInFnc);
	MakeCurve(CubicEaseInOut, "Cubic Ease In-Out", &CubicEaseInOutFnc);
	MakeCurve(QuarticEaseOut, "Quartic Ease Out", &QuarticEaseOutFnc);
	MakeCurve(QuarticEaseIn, "Quartic Ease In", &QuarticEaseInFnc);
	MakeCurve(QuarticEaseInOut, "Quartic Ease In-Out", &QuarticEaseInOutFnc);
	MakeCurve(QuinticEaseOut, "Quintic Ease Out", &QuinticEaseOutFnc);
	MakeCurve(QuinticEaseIn, "Quintic Ease In", &QuinticEaseInFnc);
	MakeCurve(QuinticEaseInOut, "Quintic Ease In-Out", &QuinticEaseInOutFnc);
	MakeCurve(SinusoidaleEaseOut, "Sinusoidale Ease Out", &SinusoidaleEaseOutFnc);
	MakeCurve(SinusoidaleEaseIn, "Sinusoidale Ease In", &SinusoidaleEaseInFnc);
	MakeCurve(SinusoidaleEaseInOut, "Sinusoidale Ease In-Out", &SinusoidaleEaseInOutFnc);
	MakeCurve(ExponentialEaseOut, "Exponential Ease Out", &ExponentialEaseOutFnc);
	MakeCurve(ExponentialEaseIn, "Exponential Ease In", &ExponentialEaseInFnc);
	MakeCurve(ExponentialEaseInOut, "Exponential Ease In-Out", &ExponentialEaseInOutFnc);
	MakeCurve(CircularEaseOut, "Circular Ease Out", &CircularEaseOutFnc);
	MakeCurve(CircularEaseIn, "Circular Ease In", &CircularEaseInFnc);
	MakeCurve(CircularEaseInOut, "Circular Ease In-Out", &CircularEaseInOutFnc);
}

void AIE21Application::Tick(float _dt, AIE21Application* _app)
{
	Previous();
	Next();

	m_t += _dt;
	if (m_t > 1)
		m_t = 0;
}

void AIE21Application::Render(AIE21Application* _app)
{
	DrawName();
	DrawGrid();
	DrawLine();
	DrawPoint();
}

void AIE21Application::EndPlay()
{
	m_t = 0;
	m_currentCurve = 0;
}


void AIE21Application::Next()
{
	if (IsKeyPressed(KEY_RIGHT))
	{
		m_currentCurve++;
		if (m_currentCurve == CurveTypeCount)
			m_currentCurve = 0;
	}
}

void AIE21Application::Previous()
{
	if (IsKeyPressed(KEY_LEFT))
	{
		m_currentCurve--;
		if (m_currentCurve < 0)
			m_currentCurve = CurveTypeCount - 1;
	}
}

void AIE21Application::DrawName()
{
	DrawText(m_curves[static_cast<ECurveType>(m_currentCurve)]->GetTitle(), 10, 10, 20, BLACK);
}

void AIE21Application::DrawGrid() const
{
	DrawRectangleRec(m_rect, WHITE);

	for (int i = 0; i < X_DIV; ++i)
	{
		const float xPos = m_rect.x + static_cast<float>(i) * X_DIV;
		DrawLineV({ xPos, m_rect.y }, { xPos, m_rect.y + m_rect.height }, GRAY);
	}

	for (int i = 0; i < Y_DIV; ++i)
	{
		const float yPos = m_rect.y + static_cast<float>(i) * Y_DIV;
		DrawLineV({ m_rect.x, yPos }, { m_rect.x + m_rect.width, yPos }, GRAY);
	}
}

void AIE21Application::DrawLine()
{
	for (int i = 0; i < static_cast<int>(LINE_DENSITY); ++i)
	{
		const float x1 = static_cast<float>(i) / LINE_DENSITY;
		const float x2 = static_cast<float>(i + 1) / LINE_DENSITY;

		const float y1 = m_curves[static_cast<ECurveType>(m_currentCurve)]->Run(x1, 0, 1);
		const float y2 = m_curves[static_cast<ECurveType>(m_currentCurve)]->Run(x2, 0, 1);

		DrawLineEx(
			{ m_rect.x + x1 * m_rect.width, m_rect.y + m_rect.height - y1 * m_rect.height },
			{ m_rect.x + x2 * m_rect.width, m_rect.y + m_rect.height - y2 * m_rect.height },
			2.f,
			BLACK
		);
	}
}

void AIE21Application::DrawPoint()
{
	DrawCircleV(
		{
			m_rect.x + m_t * m_rect.width,
			m_rect.y + m_rect.height - m_curves[static_cast<ECurveType>(m_currentCurve)]->Run(m_t, 0, 1) * m_rect.height
		},
		8.f,
		RED
	);
}

void AIE21Application::MakeCurve(const ECurveType _type, const char* _title, const Curve::CurveFnc _fnc)
{
	if (m_curves.contains(_type))
		return;

	m_curves[_type] = new Curve(_title, _fnc);
}