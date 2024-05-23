#include "TestLevel.h"

#include "Application.h"
#include "Config.h"
#include "LevelManager.h"
#include "Resources.h"

using MathLib::Vec3;

TestLevel::TestLevel()
	: ILevelBase("Test"), m_playerPos{ 0, 0 }, m_playerSpeed{ 0 }, m_world{ nullptr }, m_tank{ nullptr }, m_turret{ nullptr }, m_resolveCollision{ false }
{
}

TestLevel::~TestLevel()
{
	delete m_world;
	m_world = nullptr;
}


void TestLevel::BeginPlay()
{

	const int screenWidth = m_levelManager->GetConfig()->GetValue<int>("window", "width");
	const int screenHeight = m_levelManager->GetConfig()->GetValue<int>("window", "height");

	Resources::LoadTexture2D("tankGreen");
	Resources::LoadTexture2D("barrelGreenNew");

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

	m_playerSpeed = m_levelManager->GetConfig()->GetValue<float>("player", "speed");

}

void TestLevel::Tick(float _dt)
{
	const float rot = 240.f * _dt * DEG2RAD;

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

	
	

	m_world->Tick(_dt);


}

void TestLevel::Render()
{
	m_world->Render();
}

void TestLevel::EndPlay()
{
	Resources::UnloadAll();
}
