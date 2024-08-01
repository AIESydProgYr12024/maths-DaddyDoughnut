#pragma once

#include "MathLib/Scene/SceneObject.h"
#include "MathLib/Scene/SpriteObject.h"
#include "MathLib/Types/Mat3.h"

using MathLib::SpriteObject;
using MathLib::SceneObject;
using MathLib::Mat3;

class TestLevel;

class Turret : public SceneObject
{
public:
	Turret(Texture2D* _texture, int _speed, bool _canSpawn, TestLevel* _testLevel);
public:
	void SetRadius(const float _radius);

protected:
	void OnTick(float _dt) override;

private:
	float m_radius;
	SpriteObject* m_sprite;
	int m_speed;
	bool m_canSpawn;
	TestLevel* m_level;
};


