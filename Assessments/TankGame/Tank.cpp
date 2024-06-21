#include "Tank.h"

using MathLib::Vec2;
using MathLib::Mat3;

Tank::Tank(Texture2D* _texture)
	: m_radius{ 0.f }, m_sprite{ new SpriteObject(_texture) }
{
	SetRadius(20.f);
	m_sprite->SetParent(this);
}

void Tank::SetRadius(const float _radius)
{
	m_radius = _radius;
	m_sprite->size = Vec2{ m_radius * 2.f, m_radius * 2.f };
}

void Tank::Move(float _dt, float _speed)
{
	const float rot = 240.f * _dt * DEG2RAD;

	// Move Tank
	if (IsKeyDown(KEY_W))
		UpdateTransform(
			Mat3::CreateTranslation(Vec2::down * _dt * _speed)
		);

	if (IsKeyDown(KEY_S))
		UpdateTransform(
			Mat3::CreateTranslation(Vec2::up * _dt * _speed)
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
