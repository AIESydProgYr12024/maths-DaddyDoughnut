#include "ILevelBase.h"

// Return Level Name
const char* ILevelBase::Name() const
{
	return m_name;
}

// Return World Object
SceneObject* ILevelBase::GetWorld() const
{
	return m_world;
}

// Constructor
ILevelBase::ILevelBase(const char* _name)
	: m_name{ _name }, m_levelManager{ nullptr }, m_world{ new SceneObject }
{
}

// Destructor
ILevelBase::~ILevelBase()
{
	m_name = nullptr;
	m_levelManager = nullptr;

	delete m_world;
	m_world = nullptr;
}
