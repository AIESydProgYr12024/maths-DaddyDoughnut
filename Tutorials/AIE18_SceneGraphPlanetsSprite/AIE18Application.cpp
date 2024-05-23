#include "AIE18Application.h"

#include <raylib/raylib.h>

#include "PlanetSceneObject.h"
#include "Resources.h"

using MathLib::Mat3;

AIE18Application::AIE18Application(const int _width, const int _height, const char* _title, const Color _clrColor)
	: m_width{ _width }, m_height{ _height }, m_title{ _title }, m_running{ true }, m_clearColor{ _clrColor },
m_world(nullptr), m_sun(nullptr), m_earth(nullptr), m_moon(nullptr)
{
}

AIE18Application::~AIE18Application()
{
	delete m_world;
	m_world = nullptr;
}

void AIE18Application::Run()
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

void AIE18Application::Quit()
{
	m_running = false;
}

void AIE18Application::BeginPlay()
{
	Resources::LoadTexture2D("planets/planet5");
	Resources::LoadTexture2D("planets/planet18");
	Resources::LoadTexture2D("planets/planet6");

	m_world = new SceneObject;
	m_world->UpdateTransform(Mat3(1.f));

	m_sun = new PlanetSceneObject(Resources::GetTexture("planets/planet5"));
	m_sun->SetRadius(75.f);
	m_sun->UpdateTransform(
		Mat3::CreateTranslation(MathLib::Vec3{ static_cast<float>(m_width) * .5f, static_cast<float>(m_height) * .5f, 0.f }));
	
	m_sun->SetParent(m_world);

	
}

void AIE18Application::Tick(float _dt, AIE18Application* _app)
{
	m_sun->UpdateTransform(
		Mat3::CreateZRotation(1.f * _dt * DEG2RAD)
	);

	m_earth->UpdateTransform(
		Mat3::CreateZRotation(365.f * _dt * DEG2RAD)
	);

	m_world->Tick(_dt);
}

void AIE18Application::Render(AIE18Application* _app)
{
	m_world->Render();
}

void AIE18Application::EndPlay()
{
	Resources::UnloadAll();
}
