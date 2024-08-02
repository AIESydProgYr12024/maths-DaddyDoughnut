#include "TestLevel.h"
#include "Application.h"
#include "Config.h"
#include "LevelManager.h"
#include "Resources.h"

#include <iostream>

// Constructor
TestLevel::TestLevel()
	: ILevelBase("Test"), m_playerSpeed{ 0 },
      m_tank{ nullptr }, m_turret{ nullptr },
      m_wall1( new Wall(Vec2{300.f, 300.f}, Vec2{ 100.f, 100.f }) ),
      m_wall2( new Wall(Vec2{100.f, 100.f}, Vec2{ 100.f, 100.f }) ),
      m_wall3( new Wall(Vec2{ 700.f, 500.f }, Vec2{100.f, 300.f}) )
{
}

// Destructor
TestLevel::~TestLevel()
{
	delete m_world;
	m_world = nullptr;
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
					
					
					Hit* wallHit1 = m_bullets[i]->GetCollider()->Intersects(*m_wall1->GetCollider());
					Hit* wallHit2 = m_bullets[i]->GetCollider()->Intersects(*m_wall1->GetCollider());
					Hit* wallHit3 = m_bullets[i]->GetCollider()->Intersects(*m_wall1->GetCollider());
					if (wallHit1 != nullptr || wallHit2 != nullptr || wallHit3 != nullptr)
					{
						hasCollided = true;
						delete wallHit1, wallHit2, wallHit3;
						wallHit1, wallHit2, wallHit3 = nullptr;
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
	m_wall1->Draw(RED);
	m_wall2->Draw(RED);
	m_wall3->Draw(RED);
}

void TestLevel::EndPlay()
{
	// Unload Textures
	Resources::UnloadAll();
}