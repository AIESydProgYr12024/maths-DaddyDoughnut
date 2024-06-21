#include "LevelManager.h"

#include <ranges>

#include "Application.h"
#include "ILevelBase.h"

// Constructor
LevelManager::LevelManager(Application* _app)
	: m_app{ _app }
{
}

// Destructor
LevelManager::~LevelManager()
{
	for (const auto& level : m_levels | std::views::values)
		delete level;

	m_levels.clear();
	m_openLevels.clear();
	m_openListChanges.clear();
}

void LevelManager::Tick(const float _dt)
{
	// Loop through object to open and close marked level's
	for (auto& change : m_openListChanges)
		change();

	m_openListChanges.clear();

	// Loop through object to tick all open levels
	for (const auto& level : m_openLevels)
	{
		level->GetWorld()->Tick(_dt);
		level->Tick(_dt);
	}
}

// Render level and its world object
void LevelManager::Render() const
{
	for (const auto& level : m_openLevels)
	{
		level->Render();
		level->GetWorld()->Render();
	}
}

// Open level and Call BeginPlay function
void LevelManager::OpenLevel(const char* _name)
{
	if (!m_levels.contains(_name))
		return;

	ILevelBase* level = m_levels[_name];
	if (std::ranges::find(m_openLevels, level) != m_openLevels.end())
		return;

	m_openListChanges.emplace_back([level, this]
		{
			m_openLevels.emplace_back(level);
			level->BeginPlay();
		});
}

// Call levels EndPlay function and Close level
void LevelManager::ExitLevel(const char* _name)
{
	if (!m_levels.contains(_name))
		return;

	ILevelBase* level = m_levels[_name];
	if (std::ranges::find(m_openLevels, level) == m_openLevels.end())
		return;

	m_openListChanges.emplace_back([level, this]
		{
			level->EndPlay();
			m_openLevels.remove(level);
		});
}

// Add level to m_levels
void LevelManager::AddLevel(ILevelBase* _level)
{
	if (m_levels.contains(_level->Name()))
		return;

	m_levels[_level->Name()] = _level;
	_level->m_levelManager = this;
}

// Return pointer to aplication
Application* LevelManager::GetApp() const
{
	return m_app;
}

// Return pointer to config
Config* LevelManager::GetConfig() const
{
	return m_app->GetConfig();
}