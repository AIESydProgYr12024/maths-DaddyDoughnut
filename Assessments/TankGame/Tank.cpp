#include "Tank.h"

using MathLib::Vec2;
using MathLib::Mat3;

// Constructor
Tank::Tank(Texture2D* _texture, int _speed)
	: m_radius{ 0.f }, m_sprite{ new SpriteObject(_texture) }, m_speed{ _speed }
{
	SetRadius(20.f);
	m_sprite->SetParent(this);
}

// Set Size Of Tank
void Tank::SetRadius(const float _radius)
{
	m_radius = _radius;
	m_sprite->size = Vec2{ m_radius * 2.f, m_radius * 2.f };
}

void Tank::OnTick(float _dt)
{
	// Get Rotation speed for tick
	const float rot = 240.f * _dt * DEG2RAD;

	// Move Tank
	if (IsKeyDown(KEY_W))
		UpdateTransform(
			Mat3::CreateTranslation(Vec2::down * _dt * m_speed)
		);

	if (IsKeyDown(KEY_S))
		UpdateTransform(
			Mat3::CreateTranslation(Vec2::up * _dt * m_speed)
		);

	// Rotate Tank
	if (IsKeyDown(KEY_A))
		UpdateTransform(
			Mat3::CreateZRotation(-rot)
		);

	if (IsKeyDown(KEY_D))
		UpdateTransform(
			Mat3::CreateZRotation(rot)
		);
}
