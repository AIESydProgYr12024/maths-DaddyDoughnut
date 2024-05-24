#include "Map.h"

using MathLib::Vec2;

Map::Map(Texture2D* _texture)
	: m_radius{ 0.f }, m_sprite{ new SpriteObject(_texture) }
{
	SetRadius(20.f);
	m_sprite->SetParent(this);
}

void Map::SetRadius(const float _radius)
{
	m_radius = _radius;
	m_sprite->size = Vec2{ m_radius * 2.f, m_radius * 2.f };
}