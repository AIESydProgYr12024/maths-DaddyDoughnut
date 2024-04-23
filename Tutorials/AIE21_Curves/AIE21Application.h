#pragma once

#include <raylib/raylib.h>

#include <map>

#include "Curve.h"

using std::map;

class AIE21Application
{
public:
	AIE21Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE21Application();

public:
	void Run();
	void Quit();

private:
	int m_width;
	int m_height;
	const char* m_title;

	bool m_running;
	Color m_clearColor;

	map<ECurveType, Curve*> m_curves;
	int m_currentCurve;

	Rectangle m_rect;
	float m_t;

private:
	void BeginPlay();

	void Tick(float _dt, AIE21Application* _app);
	void Render(AIE21Application* _app);

	void EndPlay();

	void Next();
	void Previous();

	void DrawName();
	void DrawGrid() const;
	void DrawLine();
	void DrawPoint();

	void MakeCurve(ECurveType _type, const char* _title, Curve::CurveFnc _fnc);

};