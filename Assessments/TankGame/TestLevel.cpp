#include "TestLevel.h"

#include "Config.h"
#include "LevelManager.h"

TestLevel::TestLevel()
	: ILevelBase("Test"), m_playerPos{ 0, 0 }, m_playerSpeed{ 0 }
{
}

void TestLevel::BeginPlay()
{
	const int screenWidth = m_levelManager->GetConfig()->GetValue<int>("window", "width");
	const int screenHeight = m_levelManager->GetConfig()->GetValue<int>("window", "height");

	m_playerSpeed = m_levelManager->GetConfig()->GetValue<float>("player", "speed");

	m_playerPos = Vec2(static_cast<float>(screenWidth) * .5f, static_cast<float>(screenHeight) * .5f);
}

void TestLevel::Tick(float _dt)
{
	const Vec2 movement = Vec2
	{
		(static_cast<float>(IsKeyDown(KEY_D)) - static_cast<float>(IsKeyDown(KEY_A))),
		(static_cast<float>(IsKeyDown(KEY_S)) - static_cast<float>(IsKeyDown(KEY_W)))
	};

	m_playerPos += movement * m_playerSpeed * _dt;
}

void TestLevel::Render()
{
	DrawText("Hello!", static_cast<int>(m_playerPos.x), static_cast<int>(m_playerPos.y), 100, RED);
}

void TestLevel::EndPlay()
{
}
