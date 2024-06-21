#include "MathLib/Scene/SceneObject.h"

namespace MathLib
{
	// Constructor
	SceneObject::SceneObject()
		: m_transform{ Mat3(1.f) }, m_parent{ nullptr }
	{
	}

	// Destructor
	SceneObject::~SceneObject()
	{
		for (const auto& child : m_children)
			delete child;
		m_children.clear();
	}
	
	void SceneObject::Tick(float _dt)
	{
		OnTick(_dt);

		// Loop through to add and remove marked children to object
		for (auto& update : m_childlistChanges)
			update();

		m_childlistChanges.clear();

		// Loop through children and call their tick function
		for (const auto& child : m_children)
			child->Tick(_dt);
	}

	void SceneObject::Render()
	{
		OnRender();

		// Loop through children and call their update function
		for (const auto& child : m_children)
			child->Render();
	}

	// Return its Parent Object
	SceneObject* SceneObject::Parent() const
	{
		return m_parent;
	}

	// Set its Parent object
	void SceneObject::SetParent(SceneObject* _newParent, bool _deleteChild)
	{
		if(_newParent == nullptr)
		{
			if (m_parent != nullptr)
				m_parent->RemoveChild(this, _deleteChild);
		}
		else
		{
			_newParent->AddChild(this);
		}
	}

	// Return global object matrix
	Mat3 SceneObject::Global()
	{
		return m_parent != nullptr ? Local() * m_parent->Global() : Local();
	}

	// Return local object matrix
	Mat3 SceneObject::Local()
	{
		return m_transform;
	}

	// Update object's position
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

	// Add a child object
	void SceneObject::AddChild(SceneObject* _child)
	{
		m_childlistChanges.emplace_back([_child, this]
			{
				if (_child->m_parent != nullptr)
					_child->m_parent->RemoveChild(_child, false);

				_child->m_parent = this;
				m_children.emplace_back(_child);
			});
	}

	// Remove a child object
	void SceneObject::RemoveChild(SceneObject* _child, bool _deleteChild)
	{
		m_childlistChanges.emplace_back([_child, this, _deleteChild]
			{
				if (_child->m_parent == this)
				{
					_child->m_parent = nullptr;
					m_children.remove(_child);

					if (_deleteChild)
						delete _child;
				}
			});
	}
}
