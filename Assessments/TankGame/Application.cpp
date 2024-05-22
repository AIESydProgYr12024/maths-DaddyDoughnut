#include "Application.h"

#include <raylib/raylib.h>

#include "Config.h"
#include "LevelManager.h"
#include "TestLevel.h"

Application::Application()
	: m_width{ 0 }, m_height{ 0 }, m_running{ true }, m_clearColor{ BLANK }, m_config{ new Config }
{
	m_levelManager = new LevelManager(this);
}

Application::~Application()
{
	delete m_config;
	m_config = nullptr;

	delete m_levelManager;
	m_levelManager = nullptr;
}

void Application::Run()
{
	LoadConfigValues();

	InitWindow(m_width, m_height, m_title.c_str());

	BeginPlay();

	while (m_running)
	{
		Tick(GetFrameTime());

		BeginDrawing();
		ClearBackground(m_clearColor);

		Render();

		EndDrawing();

		if (WindowShouldClose())
			m_running = false;
	}

	EndPlay();

	CloseWindow();
}

void Application::Quit()
{
	m_running = false;
}

Config* Application::GetConfig() const
{
	return m_config;
}

void Application::BeginPlay()
{
	// Create all level pointers here
	m_levelManager->AddLevel(new TestLevel);

	// Open initial level
	m_levelManager->OpenLevel("Test");
}

void Application::Tick(float _dt)
{
	m_levelManager->Tick(_dt);
}

void Application::Render()
{
	m_levelManager->Render();
}

void Application::EndPlay()
{
}

void Application::LoadConfigValues()
{
	m_config->Load();

	m_width = m_config->GetValue<int>("window", "width");
	m_height = m_config->GetValue<int>("window", "height");
	m_clearColor = m_config->GetValue<Color>("window", "clrCol");
	m_title = m_config->GetValue<string>("application", "title");
}
