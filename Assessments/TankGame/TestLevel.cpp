#include "TestLevel.h"
#include "Application.h"
#include "Config.h"
#include "LevelManager.h"
#include "Resources.h"

#include <iostream>

// Constructor
TestLevel::TestLevel()
	: ILevelBase("Test"), m_playerSpeed{ 0 },
      m_tank{ nullptr }, m_turret{ nullptr }, m_map{ nullptr },
	  m_walls
	  {
		  new Rect(Vec2{ 310.f, 185.f }, Vec2{ 115.f, 140.f }) ,
		  new Rect(Vec2{ 696.f, 365.f }, Vec2{ 40.f, 205.f }) ,
		  new Rect(Vec2{ 558.f, 550.f }, Vec2{ 178.f, 20.f }) ,
		  new Rect(Vec2{ 758, 735 }, Vec2{ 65, 40 })
	  }
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

// Create bullet
void TestLevel::CreateBullet()
{
	// Add a new bullet to the bullet list
	m_bullets.emplace_back(new Bullet(Resources::GetTexture("bulletGreen")));

	m_bullets.back()->SetRadius(12.f);

	m_bullets.back()->UpdateTransform(m_turret->Global());
	m_bullets.back()->UpdateTransform(
		Mat3::CreateTranslation(Vec2::down * 80.f)
	);

	m_bullets.back()->SetParent(m_world);
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

	// Get Player Speed
	m_playerSpeed = m_levelManager->GetConfig()->GetValue<float>("player", "speed");

	// Make Tank
	m_tank = new Tank(Resources::GetTexture("tankGreen"), m_playerSpeed);
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
	m_turret = new Turret(Resources::GetTexture("barrelGreenNew"), m_playerSpeed, false, this);
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
}

void TestLevel::Tick(float _dt)
{
	// Loop Through Bullets
	for(int i = 0; i < m_bullets.size(); ++i)
	{
		if (m_bullets[i] != nullptr)
		{
			if(m_bullets[i]->Parent() != nullptr)
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