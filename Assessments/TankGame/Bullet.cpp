#include "Bullet.h"

using MathLib::Vec2;

// Constructor
Bullet::Bullet(Texture2D* _texture)
	: m_radius{ 0.f }, m_sprite{ new SpriteObject(_texture) },
	m_collider{ new MathLib::Rect(Vec2{ 50.f, 50.f }, Vec2{ 16.f, 16.f }) },
	m_hasCollided{ false }
{
	SetRadius(20.f);
	m_sprite->SetParent(this);
}

// Destructor
Bullet::~Bullet()
{
	delete m_collider;
	m_collider = nullptr;
}

// Set Size Of Bullet
void Bullet::SetRadius(const float _radius)
{
	m_radius = _radius;
	m_sprite->size = Vec2{ m_radius * 2.f, m_radius * 3.f };
}

// Move Bullet
void Bullet::Move(float _dt)
{
	UpdateTransform(
		Mat3::CreateTranslation(Vec2::down * _dt * 400.f)
	);
	m_collider->center = m_transform.GetTranslation();
}

// Return Bullet's Collider
MathLib::Rect* Bullet::GetCollider() const
{
	return m_collider;
}