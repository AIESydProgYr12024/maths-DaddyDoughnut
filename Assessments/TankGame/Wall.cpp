#include "Wall.h"

Wall::Wall()
	:m_data{ new Rect(Vec2{ 0.f, 0.f }, Vec2{ 0.f, 0.f }) }
{
}

Wall::Wall(Vec2 _position, Vec2 _size)
	:m_data{ new Rect(_position, _size) }
{
}

Wall::~Wall()
{
	delete m_data;
	m_data = nullptr;
}
