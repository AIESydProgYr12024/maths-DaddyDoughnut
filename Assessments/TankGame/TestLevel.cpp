#include "TestLevel.h"
#include "Application.h"
#include "Config.h"
#include "LevelManager.h"
#include "Resources.h"

#include <iostream>

using MathLib::Vec3;

TestLevel::TestLevel()
	: ILevelBase("Test"), m_playerPos{ 0, 0 }, m_playerSpeed{ 0 },
	 m_tank{ nullptr }, m_turret{ nullptr }, m_map{ nullptr },
	m_wall1{ new Rect(Vec2{ 310.f, 185.f }, Vec2{ 115.f, 140.f }) },
	m_wall2{ new Rect(Vec2{ 696.f, 365.f }, Vec2{ 40.f, 205.f }) },
	m_wall3{ new Rect(Vec2{ 558.f, 550.f }, Vec2{ 178.f, 20.f }) },
	m_wall4{ new Rect(Vec2{ 758, 735 }, Vec2{ 65, 40 }) },
	m_canSpawn{ false }
{
}

TestLevel::~TestLevel()
{
	delete m_world;
	m_world = nullptr;
	delete m_wall1;
	m_wall1 = nullptr;
	delete m_wall2;
	m_wall2 = nullptr;
	delete m_wall3;
	m_wall3 = nullptr;
	delete m_wall4;
	m_wall4 = nullptr;
}

void TestLevel::BeginPlay()
{

	const int screenWidth = m_levelManager->GetConfig()->GetValue<int>("window", "width");
	const int screenHeight = m_levelManager->GetConfig()->GetValue<int>("window", "height");

	Resources::LoadTexture2D("map");
	Resources::LoadTexture2D("tankGreen");
	Resources::LoadTexture2D("barrelGreenNew");
	Resources::LoadTexture2D("bulletGreen");

	m_tank = new Tank(Resources::GetTexture("tankGreen"));
	m_tank->SetRadius(50.f);
	m_tank->UpdateTransform(
		Mat3::CreateTranslation(
			Vec3{
				static_cast<float>(screenWidth) * .5f,
				static_cast<float>(screenHeight) * .5f,
				0.f
			}
		)
	);
	m_tank->SetParent(m_world);

	m_turret = new Turret(Resources::GetTexture("barrelGreenNew"));
	m_turret->SetRadius(25.f);
	m_turret->SetParent(m_tank);


	m_map = new SpriteObject(Resources::GetTexture("map"));
	m_map->size = Vec2{ 800.f, 800.f };
	m_map->UpdateTransform(
		Mat3::CreateTranslation(
			Vec3{
				static_cast<float>(screenWidth) * .5f,
				static_cast<float>(screenHeight) * .5f,
				0.f
			}
		)
	);
	m_map->SetParent(m_world);

	m_playerSpeed = m_levelManager->GetConfig()->GetValue<float>("player", "speed");
}

void TestLevel::Tick(float _dt)
{
	m_tank->Move(_dt, m_playerSpeed);
	m_turret->Move(_dt, m_playerSpeed * 2);

	//loop through bullets 
	if (!m_bullets.empty())
	{
		for (int i = 0; i < m_bullets.size();)
		{
			if (m_bullets[i] != nullptr)
			{
				m_bullets[i]->Move(_dt);


				// delete bullet if 

				Hit* wall1Hit = m_bullets[i]->GetCollider()->Intersects(*m_wall1);
				Hit* wall2Hit = m_bullets[i]->GetCollider()->Intersects(*m_wall2);
				Hit* wall3Hit = m_bullets[i]->GetCollider()->Intersects(*m_wall3);
				Hit* wall4Hit = m_bullets[i]->GetCollider()->Intersects(*m_wall4);
				if (
					wall1Hit != nullptr ||
					wall2Hit != nullptr ||
					wall3Hit != nullptr ||
					wall4Hit != nullptr ||
					fabsf(m_bullets[i]->Global().GetTranslation().x) >= static_cast<float>(m_levelManager->GetConfig()->GetValue<int>("window", "width")) ||
					fabsf(m_bullets[i]->Global().GetTranslation().y) >= static_cast<float>(m_levelManager->GetConfig()->GetValue<int>("window", "height"))
					)
				{
					m_bullets[i]->SetParent(nullptr, true);

					m_bullets.erase(m_bullets.begin() + i);
				}
				else
				{
					++i;
				}
				delete wall1Hit; wall1Hit = nullptr;
				delete wall2Hit; wall2Hit = nullptr;
				delete wall3Hit; wall3Hit = nullptr;
				delete wall4Hit; wall4Hit = nullptr;

			}
		}
	}


	if (IsKeyUp(KEY_SPACE) && !m_canSpawn)
		m_canSpawn = true;

	// Spawn Bullet 
	if (IsKeyDown(KEY_SPACE)/* && m_canSpawn*/)
	{
		m_canSpawn = false;

		m_bullets.emplace_back(new Bullet(Resources::GetTexture("bulletGreen")));
		m_bullets.back()->SetRadius(12.f);
		m_bullets.back()->UpdateTransform(m_turret->Global());

		m_bullets.back()->UpdateTransform(
			Mat3::CreateTranslation(Vec2::down * 80.f)
		);
		m_bullets.back()->SetParent(m_world);

	}

	
}

void TestLevel::Render()
{
}

void TestLevel::EndPlay()
{
	Resources::UnloadAll();
}

