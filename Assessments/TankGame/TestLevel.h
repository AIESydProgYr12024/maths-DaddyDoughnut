#pragma once

#include <vector>
#include<cstdlib>

#include "ILevelBase.h"

#include "MathLib/Types/Vec2.h"
#include "MathLib/Types/Mat3.h"
#include "MathLib/Geometry/Rect.h"
#include "MathLib/Scene/SceneObject.h"
#include "Tank.h"
#include "Turret.h"
#include "Bullet.h"
#include "Map.h"

using MathLib::Vec2;
using MathLib::Mat3;
using MathLib::Rect;
using MathLib::SceneObject;
using std::vector;

class TestLevel final : public ILevelBase
{
public:
	TestLevel();
	~TestLevel();
protected:
	void BeginPlay() override;
	void Tick(float _dt) override;
	void Render() override;
	void EndPlay() override;

private:
	Vec2 m_playerPos;
	float m_playerSpeed;
	SceneObject* m_world;
	Tank* m_tank;
	Turret* m_turret;
	vector<Bullet*> m_bullets;
	Map* m_map;
	Rect* m_wall1;
	Rect* m_wall2;
	Rect* m_wall3;
	Rect* m_wall4;
	bool m_resolveCollision;
	bool m_canSpawn;

};