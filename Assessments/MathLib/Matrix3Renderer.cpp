#include "MathLib/Matrix3Renderer.h"

#include <utility>
#include <ranges>
#include <iomanip>
#include <sstream>

#include "MathLib/MathFunctions.h"

using std::stringstream;

namespace MathLib
{
	Matrix3Renderer::ExtraInfoActions::ExtraInfoActions(string _text, function<void()> _onScroll)
		: text{ std::move(_text) }, onScroll{ std::move(_onScroll) }
	{
	}

	Matrix3Renderer::MatrixProps::MatrixProps(string _name)
		: mouseOver{ false }, m_name{ std::move(_name) }
	{
	}

	Matrix3Renderer::Matrix3Renderer(Vec2 _screenSize, Vec2 _unitSize)
		: m_screenSize{ std::move(_screenSize) }, m_unitSize{ std::move(_unitSize) }
	{
	}

	Matrix3Renderer::~Matrix3Renderer()
	{
		for (const auto& prop : m_properties | std::views::values)
			delete prop;

		m_properties.clear();
		m_matrices.clear();

		m_renderQueue.clear();
		m_uiRenderQueue.clear();
	}

	void Matrix3Renderer::BeginRender()
	{
		m_renderQueue.clear();
		m_uiRenderQueue.clear();
		m_matrices.clear();
	}

	void Matrix3Renderer::EndRender() const
	{
		DrawGrid();

		for (auto& action : m_renderQueue)
			action();

		for (auto& action : m_uiRenderQueue)
			action();
	}

	void Matrix3Renderer::DrawMatrix(const string& _name, Mat3& _mat, Color _color, const Vec2& _textAreaEditPos)
	{
		m_matrices[_name] = _mat;

		if (!m_properties.contains(_name))
			m_properties[_name] = new MatrixProps(_name);

		m_renderQueue.emplace_back([_mat, _name, _color, this]
			{
				const Vec2 origin = m_screenSize * .5f;

				const Vec2 xa = Vec2{ _mat.m1, _mat.m2 * -1.f } *m_unitSize.x;
				const Vec2 ya = Vec2{ _mat.m4, _mat.m5 * -1.f } *m_unitSize.y;
				const Vec2 za = Vec2{ _mat.m7 * m_unitSize.x, _mat.m8 * -1.f * m_unitSize.y };

				const float thickness = m_properties[_name]->mouseOver ? 3.f : 2.f;

				DrawArrow(origin + za, origin + za + xa, thickness, _color);
				DrawArrow(origin + za, origin + za + ya, thickness, _color);
			});

		m_uiRenderQueue.emplace_back([&, _name, this]
			{
				DrawMatrixEditAreaUI(_name, _textAreaEditPos, _mat, _color);
			});
	}

	void Matrix3Renderer::DrawPoint(const Vec2& _point, Color _color, float _size)
	{
		m_renderQueue.emplace_back([_point, _size, _color, this]
			{
				const Vec2 origin = m_screenSize * .5f;

				const Vec2 p =
				{
					origin.x + _point.x * m_unitSize.x,
					origin.y + _point.y * m_unitSize.y * -1.f
				};

				DrawCircleV(p, _size, _color);
			});
	}

	Mat3 Matrix3Renderer::GetMatrix(const string& _name)
	{
		if (m_matrices.contains(_name))
			return m_matrices[_name];

		return {};
	}

	void Matrix3Renderer::DrawArrow(const Vec2& _p1, const Vec2& _p2, const float _thickness, Color _color)
	{
		const Vec2 dir = Vec2::Normalised(_p2 - _p1) * (5.f + (_thickness - 1.f));
		const Vec2 pDir = { dir.y, -dir.x };

		DrawLineEx(_p1, _p2, _thickness, _color);
		DrawTriangle(_p2, _p2 - dir + pDir, _p2 - dir - pDir, _color);
	}

	string Matrix3Renderer::GetMatrixName(const Mat3& _mat)
	{
		// Identity check - all values must match
		if (Compare(_mat.m1, 1) && Compare(_mat.m2, 0) && Compare(_mat.m3, 0) &&
			Compare(_mat.m4, 0) && Compare(_mat.m5, 1) && Compare(_mat.m6, 0) &&
			Compare(_mat.m7, 0) && Compare(_mat.m8, 0) && Compare(_mat.m9, 1))
		{
			return "Identity";
		}

		// Scale Matrix
		// m1 and m5 can be anything, the rest have to be same
		// as identity
		if (Compare(_mat.m2, 0) && Compare(_mat.m3, 0) &&
			Compare(_mat.m4, 0) && Compare(_mat.m6, 0) &&
			Compare(_mat.m7, 0) && Compare(_mat.m8, 0) && Compare(_mat.m9, 1))
		{
			return "Scale";
		}

		// Translation Matrix
		// m7 and m8 can be anything, the rest have to be same
		// as identity
		if (Compare(_mat.m1, 1) && Compare(_mat.m2, 0) && Compare(_mat.m3, 0) &&
			Compare(_mat.m4, 0) && Compare(_mat.m5, 1) && Compare(_mat.m6, 0) &&
			Compare(_mat.m9, 1))
		{
			return "Translation";
		}

		// Rotation Matrix
		// length of x and y-axis must be 1
		// x and y-axis must be perpendicular (calculated via dot product);
		const float xaLen = sqrtf(_mat.m1 * _mat.m1 + _mat.m2 * _mat.m2);
		const float yaLen = sqrtf(_mat.m4 * _mat.m4 + _mat.m5 * _mat.m5);
		const float dot = _mat.m1 * _mat.m4 + _mat.m2 * _mat.m5;
		if (Compare(dot, 0) && Compare(xaLen, 1) && Compare(yaLen, 1) &&
			Compare(_mat.m3, 0) && Compare(_mat.m6, 0) &&
			Compare(_mat.m7, 0) && Compare(_mat.m8, 0) && Compare(_mat.m9, 1))
		{
			const string deg = FloatStringPrecise(atan2f(_mat.m2, _mat.m1) * 180.0f / PI, 2);

			return "Rotation (" + deg + ")";
		}

		// any other configuration...
		// than it's just a "transform" matrix
		return "Transform";
	}

	bool Matrix3Renderer::IsPointInRect(const Vec2& _vec, const Rectangle _rect)
	{
		return _vec.x >= _rect.x && _vec.x < _rect.x + _rect.width && _vec.y >= _rect.y && _vec.y < _rect.y + _rect.height;
	}

	void Matrix3Renderer::RotateVector(const float _amount, float& _x, float& _y)
	{
		const float xRotated = _x * cosf(_amount) - _y * sinf(_amount);
		const float yRotated = _x * sinf(_amount) + _y * cosf(_amount);

		_x = xRotated;
		_y = yRotated;
	}

	string Matrix3Renderer::FloatStringPrecise(const float _val, const int _precision)
	{
		stringstream stream;

		stream << std::fixed << std::setprecision(_precision) << _val;

		return stream.str();
	}

	void Matrix3Renderer::DrawGrid() const
	{
		const Vec2 centerPos = m_screenSize * .5f;
		constexpr Color col = LIGHTGRAY;

		// Horizontal Lines
		const int numRows = static_cast<int>(m_screenSize.y / m_unitSize.y);
		const int hNumRows = numRows / 2 + 1;
		for (int i = -hNumRows; i < hNumRows; ++i)
		{
			const float thickness = static_cast<float>(i == 0 ? 2 : 1);
			const float yOffset = centerPos.y + static_cast<float>(i) * m_unitSize.y;

			DrawLineEx({ 0, yOffset }, { m_screenSize.x, yOffset }, thickness, col);
		}

		// Vertical Lines
		const int numCols = static_cast<int>(m_screenSize.x / m_unitSize.x);
		const int hNumCols = numCols / 2 + 1;
		for (int i = -hNumCols; i < hNumCols; ++i)
		{
			const float thickness = static_cast<float>(i == 0 ? 2 : 1);
			const float xOffset = centerPos.x + static_cast<float>(i) * m_unitSize.x;

			DrawLineEx({ xOffset, 0 }, { xOffset, m_screenSize.y }, thickness, col);
		}
	}

	void Matrix3Renderer::DrawMatrixEditAreaUI(const string& _name, const Vec2& _pos, Mat3& _mat, Color _color)
	{
		MatrixProps* props = m_properties[_name];

		const Vec2 mousePos = { GetMousePosition().x, GetMousePosition().y };

		constexpr int TW = 40;
		constexpr int TH = 20;

		// List of Extra stuff to displaying in the UI
		const list<ExtraInfoActions> extraInfo = GetExtraInfoActions(_name, _mat.data, _mat);

		// Draw Title bg rectangle
		// Draw MatrixComponents rectangle
		// Draw Extra Info Rectangle
		//===============================================================
		const Rectangle titleRect = { _pos.x, _pos.y, TW * 3, 15 };
		const Rectangle matRect = { _pos.x, _pos.y + 15, TW * 3, TH * 3 };
		const Rectangle extraRect = { matRect.x, matRect.y + matRect.height, matRect.width, static_cast<float>(extraInfo.size()) * 15 + 5 };
		const Rectangle fullRect = { titleRect.x, titleRect.y, titleRect.width, titleRect.height + matRect.height + extraRect.height };

		// draw box for title
		DrawRectangleRec(titleRect, DARKGRAY);
		DrawText(_name.c_str(), static_cast<int>(titleRect.x) + 5, static_cast<int>(titleRect.y) + 2, 10, RAYWHITE);

		// draw the box where our matrix values go
		Color matBgColor = _color;
		matBgColor.a = 16;
		DrawRectangleRec(matRect, WHITE);
		DrawRectangleRec(matRect, matBgColor);

		// draw box for the extra info
		DrawRectangleRec(extraRect, GRAY);
		DrawRectangleLinesEx(fullRect, 1, DARKGRAY);
		//===============================================================

		props->mouseOver = IsPointInRect(mousePos, fullRect);

		// draw the text for each matrix value
		// ==============================================================
		for (int i = 0; i < MAT_3_SIZE; ++i)
		{
			const int yId = i % 3;
			const int xId = i / 3;
			const int xPos = xId * TW + static_cast<int>(matRect.x) + 6;
			const int yPos = yId * TH + static_cast<int>(matRect.y) + 6;
			DrawText(FloatStringPrecise(_mat.data[i], 3).c_str(), xPos, yPos, 10, GRAY);
		}
		// ==============================================================

		// draw the highlight box over the element the mouse is sitting over
		if (IsPointInRect(mousePos, matRect))
		{
			// convert mouse pos to Row/Col index
			// should give value between 0 and 3 because were only working with 3x3 matrix.
			const int mpxId = static_cast<int>((mousePos.x - matRect.x)) / TW;
			const int mpyId = static_cast<int>((mousePos.y - matRect.y)) / TH;
			const int mpIndex = mpxId * 3 + mpyId;

			// draw colored box over the value that the mouse is over.
			DrawRectangle(
				mpxId * TW + static_cast<int>(matRect.x),
				mpyId * TH + static_cast<int>(matRect.y),
				TW,
				TH,
				{
					_color.r,
					_color.g,
					_color.b,
					64
				}
			);

			// Draw the variable name, col and row in the title
			// might be useful for debugging
			const string indexText = "M{" + std::to_string(mpIndex + 1) + "}:[{" + std::to_string(mpxId) + "},{" + std::to_string(mpyId) + "}]";
			const int indexTextWidth = MeasureText(indexText.c_str(), 10);
			DrawText(
				indexText.c_str(),
				static_cast<int>(titleRect.x + titleRect.width) - indexTextWidth - 10,
				static_cast<int>(titleRect.y + 3),
				10,
				RAYWHITE
			);

			// if the mouse wheel has scrolled update the matrix
			if (GetMouseWheelMove() != 0.0f)
			{
				_mat.data[mpxId * 3 + mpyId] -= GetMouseWheelMove() * 0.1f;
				ModifyMatrix(_name, _mat.data, _mat);
			}
		}

		// loop through the extra info list, draw and handle input
		constexpr int ITEM_HEIGHT = 15;
		for (int i = 0; i < static_cast<int>(extraInfo.size()); i++)
		{
			const Rectangle itemRect = 
			{
				extraRect.x,
				extraRect.y + static_cast<float>(i * ITEM_HEIGHT),
				extraRect.width,
				ITEM_HEIGHT
			};
			
			auto iter = extraInfo.begin();
			std::advance(iter, i);

			// is the mouse within the rect bounds
			if (IsPointInRect(mousePos, itemRect))
			{
				// draw box to show mouse hover
				DrawRectangleRec(itemRect, DARKGRAY);

				// call the items onScroll method when mouse wheel moves.
				if (GetMouseWheelMove() != 0.0f)
					iter->onScroll();
			}

			DrawText(
				iter->text.c_str(), 
				static_cast<int>(extraRect.x) + 10, 
				static_cast<int>(itemRect.y) + 3, 
				10, 
				RAYWHITE
			);
		}
	}

	void Matrix3Renderer::ModifyMatrix(const string& _name, const float* _arr, Mat3& _mat)
	{
		_mat.m1 = _arr[0];
		_mat.m2 = _arr[1];
		_mat.m3 = _arr[2];
		_mat.m4 = _arr[3];
		_mat.m5 = _arr[4];
		_mat.m6 = _arr[5];
		_mat.m7 = _arr[6];
		_mat.m8 = _arr[7];
		_mat.m9 = _arr[8];

		m_matrices[_name] = _mat;
	}

	list<Matrix3Renderer::ExtraInfoActions> Matrix3Renderer::GetExtraInfoActions(const string& _name, float* _arr, Mat3& _mat)
	{
		list<ExtraInfoActions> extraInfo;

		extraInfo.emplace_back(
			GetMatrixName(_mat),
			[&, this]
			{
				const string text = GetMatrixName(_mat);
				if (!text.starts_with("Rotation"))
					return;

				const float scrollVal = GetMouseWheelMove();
				RotateVector(scrollVal * .01f, _arr[0], _arr[1]);
				RotateVector(scrollVal * .01f, _arr[3], _arr[4]);
				ModifyMatrix(_name, _arr, _mat);
			}
		);

		extraInfo.emplace_back(
			"x scale: " + FloatStringPrecise(Vec2{ _mat.m4, _mat.m5 }.Magnitude(), 3),
			[&, this]
			{
				const float len = sqrtf(_arr[0] * _arr[0] + _arr[1] * _arr[1]);
				if (!(len > 0))
					return;

				const float scrollVal = GetMouseWheelMove();
				_arr[0] += _arr[0] / len * scrollVal * 0.1f;
				_arr[1] += _arr[1] / len * scrollVal * 0.1f;
				ModifyMatrix(_name, _arr, _mat);
			}
		);

		extraInfo.emplace_back(
			"x scale: " + FloatStringPrecise(Vec2{ _mat.m4, _mat.m5 }.Magnitude(), 3),
			[&, this]
			{
				const float len = sqrtf(_arr[3] * _arr[3] + _arr[4] * _arr[4]);
				if (!(len > 0))
					return;

				const float scrollVal = GetMouseWheelMove();
				_arr[3] += _arr[3] / len * scrollVal * 0.1f;
				_arr[4] += _arr[4] / len * scrollVal * 0.1f;
				ModifyMatrix(_name, _arr, _mat);
			}
		);

		return extraInfo;
	}
}
