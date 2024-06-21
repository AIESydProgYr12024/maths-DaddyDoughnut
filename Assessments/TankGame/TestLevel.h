#pragma once

#include <vector>
#include<cstdlib>

#include "ILevelBase.h"

#include "MathLib/Types/Vec2.h"
#include "MathLib/Types/Mat3.h"
#include "MathLib/Geometry/Rect.h"
#include "MathLib/Scene/SceneObject.h"
#include "MathLib/Geometry/Hit.h"
#include "Tank.h"
#include "Turret.h"
#include "Bullet.h"

using MathLib::Vec2;
using MathLib::Mat3;
using MathLib::Rect;
using MathLib::SceneObject;
using MathLib::Hit;
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
	Tank* m_tank;
	Turret* m_turret;
	vector<Bullet*> m_bullets;
	SpriteObject* m_map;
	Rect* m_wall1;
	Rect* m_wall2;
	Rect* m_wall3;
	Rect* m_wall4;
	bool m_canSpawn;
};