#include "AIE17Application.h"

#include <raylib/raylib.h>

#include "PlanetSceneObject.h"

#include "MathLib/MathFunctions.h"

using MathLib::Mat3;

AIE17Application::AIE17Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor },
m_world{ new SceneObject },
m_sun{ new PlanetSceneObject(75.f, YELLOW) },
m_earth{ new PlanetSceneObject(40.f, BLUE) },
m_moon{ new PlanetSceneObject(10.f, GRAY)}
{
}

AIE17Application::~AIE17Application()
{
	delete m_world;
	m_world = nullptr;
}

void AIE17Application::Run()
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

void AIE17Application::Quit()
{
	m_running = false;
}

void AIE17Application::BeginPlay()
{
	m_world->UpdateTransform(Mat3());

	m_sun->UpdateTransform(
		Mat3::CreateTranslation(
			{
				static_cast<float>(m_width) * .5f,
				static_cast<float>(m_height) * .5f,
			}
			)
	);
	m_sun->SetParent(m_world);

	m_earth->UpdateTransform(
		Mat3::CreateTranslation({ 200.f, 0.f })
	);
	m_earth->SetParent(m_sun);

	m_moon->UpdateTransform(
		Mat3::CreateTranslation({ 100.f, 0.f })
	);
	m_moon->SetParent(m_earth);
}

void AIE17Application::Tick(float _dt, AIE17Application* _app)
{
	m_sun->UpdateTransform(
		Mat3::CreateZRotation(1.f * _dt * DEG2RAD)
	);

	m_earth->UpdateTransform(
		Mat3::CreateZRotation(365.f * _dt * DEG2RAD)
	);

	m_world->Tick(_dt);

}

void AIE17Application::Render(AIE17Application* _app)
{
	m_world->Render();
}

void AIE17Application::EndPlay()
{
}
