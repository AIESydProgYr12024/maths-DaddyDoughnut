#pragma once

#include "MathLib/Types/Vec2.h"
#include "MathLib/Geometry/Rect.h"
#include "MathLib/Geometry/Hit.h"
#include "MathLib/MathFunctions.h"

using MathLib::Vec2;
using MathLib::Rect;
using MathLib::Hit;

class Wall
{
public:
	Wall();
	Wall(Vec2 _position, Vec2 _size);
	~Wall();

public:

private:
	Rect* m_data;

};

