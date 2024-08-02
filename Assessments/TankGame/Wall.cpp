#include "Wall.h"

Wall::Wall()
	:m_collider(nullptr)
{
}

Wall::Wall(Vec2 _center, Vec2 _extents)
	:m_collider{ new Rect(_center, _extents) }
{
}

Wall::~Wall()
{
	// Delete Rect
	delete m_collider;
	m_collider = nullptr;
}

void Wall::Draw(Color _color)
{
	// Render wall
	DrawRectangleV(m_collider->Min(), m_collider->extents * 2, _color);
	// Render wall outline
	DrawRectangleLinesEx(*m_collider, 2.f, BLACK);
}

Rect* Wall::GetCollider()
{
	// Return rect
	return m_collider;
}

