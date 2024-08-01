#include "Turret.h"

#include "TestLevel.h"

using MathLib::Vec2;

// Constructor
Turret::Turret(Texture2D* _texture, int _speed, bool _canSpawn, TestLevel* _testLevel)
	: m_radius{ 0.f }, m_sprite{ new SpriteObject(_texture) }, m_speed{ _speed }, 
	m_canSpawn{ _canSpawn }, m_level{ _testLevel }
{
	SetRadius(20.f);
	m_sprite->SetParent(this);
}

// Set Size of Turret
void Turret::SetRadius(const float _radius)
{
	m_radius = _radius;
	m_sprite->size = Vec2{ m_radius * 2.f, m_radius * 6.f };
}

void Turret::OnTick(float _dt)
{
	const float rot = 240.f * _dt * DEG2RAD;

	if (IsKeyUp(KEY_SPACE))
		m_canSpawn = true;

	if (IsKeyDown(KEY_SPACE) && m_canSpawn)
	{
		m_canSpawn = true;
		
		// spawn bullet some how
		m_level->CreateBullet();

	}
	
	// Rotate turret
	if (IsKeyDown(KEY_Q))
		UpdateTransform(
			Mat3::CreateZRotation(-rot)
		);

	if (IsKeyDown(KEY_E))
		UpdateTransform(
			Mat3::CreateZRotation(rot)
		);
}
