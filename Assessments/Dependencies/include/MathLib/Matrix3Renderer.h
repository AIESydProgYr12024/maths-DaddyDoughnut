#pragma once

#include "MathLib/Types/Vec2.h"
#include "MathLib/Types/Mat3.h"

#include <list>
#include <map>
#include <functional>
#include <string>

using std::list;
using std::map;
using std::function;
using std::string;

namespace MathLib
{
	class Matrix3Renderer
	{
	private:
		class ExtraInfoActions
		{
		public:
			string text;
			function<void()> onScroll;

		public:
			ExtraInfoActions(string _text, function<void()> _onScroll);

		};

		class MatrixProps
		{
		public:
			bool mouseOver;

		public:
			MatrixProps(string _name);

		private:
			string m_name;

		};

	public:
		Matrix3Renderer() = delete;
		Matrix3Renderer(Vec2 _screenSize, Vec2 _unitSize);

		~Matrix3Renderer();

	public:
		void BeginRender();
		void EndRender() const;

		void DrawMatrix(const string& _name, Mat3& _mat, Color _color, const Vec2& _textAreaEditPos);
		void DrawPoint(const Vec2& _point, Color _color, float _size);

		Mat3 GetMatrix(const string& _name);

	private:
		Vec2 m_screenSize;
		Vec2 m_unitSize;

		list<function<void()>> m_uiRenderQueue;
		list<function<void()>> m_renderQueue;

		map<string, MatrixProps*> m_properties;
		map<string, Mat3> m_matrices;

	private:
		static void DrawArrow(const Vec2& _p1, const Vec2& _p2, float _thickness, Color _color);
		static string GetMatrixName(const Mat3& _mat);

		static bool IsPointInRect(const Vec2& _vec, Rectangle _rect);

		static void RotateVector(float _amount, float& _x, float& _y);
		static string FloatStringPrecise(float _val, int _precision);

	private:
		void DrawGrid() const;
		void DrawMatrixEditAreaUI(const string& _name, const Vec2& _pos, Mat3& _mat, Color _color);

		void ModifyMatrix(const string& _name, const float* _arr, Mat3& _mat);

		list<ExtraInfoActions> GetExtraInfoActions(const string& _name, float* _arr, Mat3& _mat);

	};
}