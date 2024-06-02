#include "TestLevel.h"


#include <iostream>

#include "Application.h"
#include "Config.h"
#include "LevelManager.h"
#include "Resources.h"

using MathLib::Vec3;

TestLevel::TestLevel()
	: ILevelBase("Test"), m_playerPos{ 0, 0 }, m_playerSpeed{ 0 },
m_world{ nullptr }, m_tank{ nullptr }, m_turret{ nullptr }, m_bullets{  }, m_map{ nullptr },
m_wall1{ new Rect(Vec2{ 310.f, 185.f }, Vec2{ 115.f, 140.f }) },
m_wall2{ new Rect(Vec2{ 696.f, 365.f }, Vec2{ 40.f, 205.f }) },
m_wall3{ new Rect(Vec2{ 558.f, 550.f }, Vec2{ 178.f, 20.f }) },
m_wall4{ new Rect(Vec2{ 758, 735 }, Vec2{ 65, 40 }) },
m_resolveCollision{ false }, m_canSpawn{ false }
{
}

TestLevel::~TestLevel()
{
	delete m_world;
	m_world = nullptr;
	delete m_wall1;
	m_wall1 = nullptr;
}


void TestLevel::BeginPlay()
{

	const int screenWidth = m_levelManager->GetConfig()->GetValue<int>("window", "width");
	const int screenHeight = m_levelManager->GetConfig()->GetValue<int>("window", "height");

	Resources::LoadTexture2D("map");
	Resources::LoadTexture2D("tankGreen");
	Resources::LoadTexture2D("barrelGreenNew");
	Resources::LoadTexture2D("bulletGreen");
	

	m_world = new SceneObject;
	m_world->UpdateTransform(Mat3(1.f));

	

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

	m_map = new Map(Resources::GetTexture("map"));
	m_map->SetRadius(400.f);
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
	
	const float rot = 240.f * _dt * DEG2RAD;

	// Bullet Spawn

	if (IsKeyUp(KEY_SPACE) && !m_canSpawn)
	{
		
		m_canSpawn = true;
	}
	if (IsKeyDown(KEY_SPACE) && m_canSpawn)
	{
		//Resources::UnloadAll();

		m_canSpawn = false;

		m_bullets.emplace_back(new Bullet(Resources::GetTexture("bulletGreen")));
		m_bullets.back()->SetRadius(12.f);
		m_bullets.back()->UpdateTransform(m_turret->Global());

		m_bullets.back()->UpdateTransform(
			Mat3::CreateTranslation(Vec2::down * 80.f)
		);
		//m_bullets.back()->SetParent(m_world);
		
	}

	// -------------

	if (IsKeyDown(KEY_Q))
		m_turret->UpdateTransform(
			Mat3::CreateZRotation(-rot / 2)
		);
	if (IsKeyDown(KEY_E))
		m_turret->UpdateTransform(
			Mat3::CreateZRotation(rot / 2)
		);
	if (IsKeyDown(KEY_W))
		m_tank->UpdateTransform(
			Mat3::CreateTranslation(Vec2::down * _dt * m_playerSpeed)
		);

	if (IsKeyDown(KEY_S))
		m_tank->UpdateTransform(
			Mat3::CreateTranslation(Vec2::up * _dt * m_playerSpeed)
		);

	if (IsKeyDown(KEY_A))
	{
		m_tank->UpdateTransform(
			Mat3::CreateZRotation(-rot)
		);
	}
	if (IsKeyDown(KEY_D))
		m_tank->UpdateTransform(
			Mat3::CreateZRotation(rot)
		);


	if (m_bullets.size() >= 1)
	{
		for (int i = 0; i < m_bullets.size();)
		{
			if (m_bullets[i] != nullptr)
			{
				m_bullets[i]->Move(_dt);

				// delete bullet if 
				if (
				m_bullets[i]->GetCollider()->Intersects(*m_wall1) != nullptr || 
				m_bullets[i]->GetCollider()->Intersects(*m_wall2) != nullptr || 
				m_bullets[i]->GetCollider()->Intersects(*m_wall3) != nullptr || 
				m_bullets[i]->GetCollider()->Intersects(*m_wall4) != nullptr || 
				abs(m_bullets[i]->Global().GetTranslation().x) >= static_cast<float>(m_levelManager->GetConfig()->GetValue<int>("window", "width")) ||
				abs(m_bullets[i]->Global().GetTranslation().y) >= static_cast<float>(m_levelManager->GetConfig()->GetValue<int>("window", "height"))
				)
				{
					
					m_levelManager->GetConfig()->GetValue<int>("window", "height");

					m_bullets[i]->SetParent(nullptr);
					m_bullets[i]->SetHasCollided(true);

					delete m_bullets[i];
					
					m_bullets.erase(m_bullets.begin() + i);
				}
				else
				{
					++i;
				}
			}
		}
		
	}

	m_world->Tick(_dt);
}


void TestLevel::Render()
{
	if (m_bullets.size() >= 1)
	{
		for (int i = 0; i < m_bullets.size(); ++i)
		{
			DrawRectangleLinesEx(*m_bullets[i]->GetCollider(), 1.f, BLACK);
		}
	}
	DrawRectangleLinesEx(*m_wall1, 1.f, BLACK);
	DrawRectangleLinesEx(*m_wall2, 1.f, BLACK);
	DrawRectangleLinesEx(*m_wall3, 1.f, BLACK);
	DrawRectangleLinesEx(*m_wall4, 1.f, BLACK);
	
	m_world->Render();
}

void TestLevel::EndPlay()
{
	Resources::UnloadAll();
}
