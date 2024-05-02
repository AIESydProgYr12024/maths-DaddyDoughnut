#pragma once

#include <raylib/raylib.h>

#include "MathLib/Scene/SceneObject.h"

using MathLib::SceneObject;

class PlanetSceneObject;

class AIE17Application
{
public:
	AIE17Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE17Application();

public:
	void Run();
	void Quit();

private:
	int m_width;
	int m_height;
	const char* m_title;

	bool m_running;
	Color m_clearColor;

	SceneObject* m_world;
	PlanetSceneObject* m_sun;
	PlanetSceneObject* m_earth;
	PlanetSceneObject* m_moon;
private:
	void BeginPlay();

	void Tick(float _dt, AIE17Application* _app);
	void Render(AIE17Application* _app);

	void EndPlay();

};