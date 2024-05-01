#pragma once

#include <raylib/raylib.h>

#include <MathLib/Types/Vec2.h>

using MathLib::Vec2;

class AIE06Application
{
public:
	AIE06Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE06Application();

public:
	void Run();
	void Quit();

private:
	int m_width;
	int m_height;
	const char* m_title;

	bool m_running;
	Color m_clearColor;

	Vec2 m_playerPos;
	Vec2 m_playerMoveDir;
	float m_playerMoveSpeed;

	Rectangle m_finishLine;
	Vec2 m_finishLineDir;

	int m_lapCount;
	bool m_isInside;


private:
	void BeginPlay();

	void Tick(float _dt, AIE06Application* _app);
	void Render(AIE06Application* _app);

	void EndPlay();

	void DrawUI();
	void DrawPlayer();
	void DrawFinishLine();

};