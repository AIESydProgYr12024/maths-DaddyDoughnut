#include "Turret.h"

using MathLib::Vec2;

Turret::Turret(Texture2D* _texture)
	: m_radius{ 0.f }, m_sprite{ new SpriteObject(_texture) }
{
	SetRadius(20.f);
	m_sprite->SetParent(this);
}

void Turret::SetRadius(const float _radius)
{
	m_radius = _radius;
	m_sprite->size = Vec2{ m_radius * 2.f, m_radius * 6.f };
}