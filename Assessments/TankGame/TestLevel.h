#pragma once

#include <vector>

#include "MathLib/Types/Vec2.h"
#include "MathLib/Types/Vec3.h"
#include "MathLib/Types/Mat3.h"
#include "MathLib/Geometry/Rect.h"
#include "MathLib/Geometry/Hit.h"

using std::vector;

using MathLib::Vec2;
using MathLib::Vec3;
using MathLib::Mat3;
using MathLib::Rect;
using MathLib::Hit;

#include "ILevelBase.h"
#include "Tank.h"
#include "Turret.h"
#include "Bullet.h"
#include "Wall.h"

class Tank;
class Turret;
class Bullet;

class TestLevel final : public ILevelBase
{
public:
	TestLevel();
	~TestLevel() override;

public:
	void CreateBullet();

protected:
	void BeginPlay() override;
	void Tick(float _dt) override;
	void Render() override;
	void EndPlay() override;

private:
	float m_playerSpeed;
	Tank* m_tank;
	Turret* m_turret;
	vector<Bullet*> m_bullets;
	Wall* m_wall1;
	Wall* m_wall2;
	Wall* m_wall3;
};