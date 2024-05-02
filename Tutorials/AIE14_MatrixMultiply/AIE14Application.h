#pragma once

#include <raylib/raylib.h>
#include "MathLib/Matrix3Renderer.h"
#include <vector>

using MathLib::Vec2;
using MathLib::Mat3;
using MathLib::Matrix3Renderer;
using std::vector;

class MatrixMultiplyPair
{
public:
	const char* label;
	Mat3 a;
	Mat3 b;

public:
	MatrixMultiplyPair(const char* _label, Mat3 _a, Mat3 _b);


};

class AIE14Application
{
public:
	AIE14Application(int _width, int _height, const char* _title, Color _clrColor);
	~AIE14Application();

public:
	void Run();
	void Quit();

private:
	int m_width;
	int m_height;
	const char* m_title;

	bool m_running;
	Color m_clearColor;

	Mat3 m_matrixA;
	Mat3 m_matrixB;
	Mat3 m_matrixC;
	Matrix3Renderer* m_renderer;

	int m_currentIndex;

	vector<MatrixMultiplyPair*> m_pairs;
private:
	void BeginPlay();

	void Tick(float _dt, AIE14Application* _app);
	void Render(AIE14Application* _app);

	void EndPlay();

	void Swap(Mat3& _a, Mat3& _b) const;
	void UpdateSelectedMatrix();
	void PopulateMatrixPairs();

};