#include "Wall.h"

Wall::Wall(Vec2 _center, Vec2 _extents)
	:m_collider( new Rect(_center, _extents) ) 
{
}

void Wall::Draw(Color _color)
{
	DrawRectangleV(m_collider->center, m_collider->extents, _color);
}

Rect* Wall::GetCollider()
{
	return m_collider;
}

