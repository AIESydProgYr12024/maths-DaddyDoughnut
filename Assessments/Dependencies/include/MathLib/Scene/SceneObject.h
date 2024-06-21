#pragma once
#include <list>
#include <functional>

#include "MathLib/Types/Mat3.h"
using std::list;
using std::pair;
using std::function;
namespace MathLib
{
	class SceneObject
	{
	public:
		SceneObject();
		virtual ~SceneObject();

	public:
		void Tick(float _dt);
		void Render();

		SceneObject* Parent() const;
		void SetParent(SceneObject* _newParent, bool _deleteChild = false);

		Mat3 Global();
		Mat3 Local();
		void UpdateTransform(const Mat3& _transform);

	protected:
		Mat3 m_transform;

	protected:
		virtual void OnTick(float _dt);
		virtual void OnRender();

	private:
		list<function<void()>> m_childlistChanges;

		list<SceneObject*> m_children;
		SceneObject* m_parent;

	private:
		void AddChild(SceneObject* _child);
		void RemoveChild(SceneObject* _child, bool _deleteChild);
	};
}