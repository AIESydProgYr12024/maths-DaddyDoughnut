#include "TestLevel.h"
#include "Application.h"
#include "Config.h"
#include "LevelManager.h"
#include "Resources.h"

#include <iostream>

using MathLib::Vec3;

// Constructor
TestLevel::TestLevel()
	: ILevelBase("Test"),
	  m_playerPos{ 0, 0 }, m_playerSpeed{ 0 },
      m_tank{ nullptr }, m_turret{ nullptr }, m_map{ nullptr },
	  m_walls
	  {
		  new Rect(Vec2{ 310.f, 185.f }, Vec2{ 115.f, 140.f }) ,
		  new Rect(Vec2{ 696.f, 365.f }, Vec2{ 40.f, 205.f }) ,
		  new Rect(Vec2{ 558.f, 550.f }, Vec2{ 178.f, 20.f }) ,
		  new Rect(Vec2{ 758, 735 }, Vec2{ 65, 40 })
	  },
	  m_canSpawn{ false }
{
}

// Destructor
TestLevel::~TestLevel()
{
	delete m_world;
	m_world = nullptr;

	for(Rect* wall : m_walls)
	{
		delete wall;
		wall = nullptr;
	}
}

void TestLevel::BeginPlay()
{
	// Get Screen Size
	const int screenWidth = m_levelManager->GetConfig()->GetValue<int>("window", "width");
	const int screenHeight = m_levelManager->GetConfig()->GetValue<int>("window", "height");

	// Load Textures
	Resources::LoadTexture2D("map");
	Resources::LoadTexture2D("tankGreen");
	Resources::LoadTexture2D("barrelGreenNew");
	Resources::LoadTexture2D("bulletGreen");

	// Make Tank
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

	// Make Turret
	m_turret = new Turret(Resources::GetTexture("barrelGreenNew"));
	m_turret->SetRadius(25.f);
	m_turret->SetParent(m_tank);

	// Make Map
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

	// Get Player Speed
	m_playerSpeed = m_levelManager->GetConfig()->GetValue<float>("player", "speed");
}

void TestLevel::Tick(float _dt)
{
	// Move Player
	m_tank->Move(_dt, m_playerSpeed);
	m_turret->Move(_dt, m_playerSpeed * 2);

	// Loop Through Bullets
	for(int i = 0; i < m_bullets.size(); ++i)
	{
		if (m_bullets[i] != nullptr)
		{
			bool hasCollided = false;

			// Move Bullet
			m_bullets[i]->Move(_dt);

			// Check If Bullet Out Of Bounds
			if (
			fabsf(m_bullets[i]->Global().GetTranslation().x) >= static_cast<float>(m_levelManager->GetConfig()->GetValue<int>("window", "width")) ||
			fabsf(m_bullets[i]->Global().GetTranslation().y) >= static_cast<float>(m_levelManager->GetConfig()->GetValue<int>("window", "height")))
			{
				hasCollided = true;
			}
			else 
			{
				// Check If Bullet Has Collided
				for (Rect* wall : m_walls)
				{
					Hit* wallHit = m_bullets[i]->GetCollider()->Intersects(*wall);
					if (wallHit != nullptr)
					{
						hasCollided = true;
						delete wallHit;
						wallHit = nullptr;
					}
				}
			}

			// Delete Bullet If It Collided
			if (hasCollided == true)
			{
				m_bullets[i]->SetParent(nullptr, true);

				m_bullets.erase(m_bullets.begin() + i);

				--i;
			}
		}
	}

	// Spawn Bullet 
	if (IsKeyUp(KEY_SPACE))
		m_canSpawn = true;

	if (IsKeyDown(KEY_SPACE) && m_canSpawn)
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
	// Unload Textures
	Resources::UnloadAll();
}