#pragma once

#include "ILevelBase.h"

#include "MathLib/Types/Vec2.h"

using MathLib::Vec2;

class TestLevel final : public ILevelBase
{
public:
	TestLevel();

protected:
	void BeginPlay() override;
	void Tick(float _dt) override;
	void Render() override;
	void EndPlay() override;

private:
	Vec2 m_playerPos;
	float m_playerSpeed;

};