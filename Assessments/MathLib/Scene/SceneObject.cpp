#include "MathLib/Scene/SceneObject.h"




namespace MathLib
{

	SceneObject::SceneObject()
		: m_transform{ Mat3(1.f) }, m_parent{ nullptr }
	{
		
	}

	SceneObject::~SceneObject()
	{
		for (const auto& child : m_children)
			delete child;
		m_children.clear();
	}

	void SceneObject::Tick(float _dt)
	{
		OnTick(_dt);

		for (auto& update : m_childlistChanges)
			update();

		m_childlistChanges.clear();

		for (const auto& child : m_children)
			child->Tick(_dt);
	}

	void SceneObject::Render()
	{
		OnRender();

		for (const auto& child : m_children)
			child->Render();
	}

	SceneObject* SceneObject::Parent() const
	{
		return m_parent;
	}

	void SceneObject::SetParent(SceneObject* _newParent)
	{
		if(_newParent == nullptr)
		{
			if (m_parent != nullptr)
				m_parent->RemoveChild(this);
		}
		else
		{
			_newParent->AddChild(this);
		}
	}

	Mat3 SceneObject::Global()
	{
		return m_parent != nullptr ? Local() * m_parent->Global() : Local();
	}

	Mat3 SceneObject::Local()
	{
		return m_transform;
	}

	void SceneObject::UpdateTransform(const Mat3& _transform)
	{
		m_transform = _transform * m_transform;
	}

	void SceneObject::OnTick(float _dt)
	{
	}

	void SceneObject::OnRender()
	{
	}

	void SceneObject::AddChild(SceneObject* _child)
	{
		m_childlistChanges.emplace_back([_child, this]
		{
			if (_child->m_parent != nullptr)
				_child->m_parent->RemoveChild(_child);

			_child->m_parent = this;
			m_children.emplace_back(_child);
		});
	}

	void SceneObject::RemoveChild(SceneObject* _child)
	{
		m_childlistChanges.emplace_back([_child, this]
			{
				if (_child->m_parent == this)
				{
					_child->m_parent = nullptr;
					m_children.remove(_child);
				}
			});

	}
}
