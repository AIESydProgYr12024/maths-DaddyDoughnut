#include "Resources.h"

#include <ranges>
#include <sstream>

using std::stringstream;

map<string, Texture2D> Resources::m_textures;

Texture2D* Resources::GetTexture(const string& _id)
{
	if (m_textures.contains(_id))
		return &m_textures[_id];

	return nullptr;
}

void Resources::LoadTexture2D(const string& _name)
{
	if (!m_textures.contains(_name))
	{
		stringstream stream;
		stream << "./assets/";
		stream << _name;
		stream << ".png";

		m_textures[_name] = LoadTexture(stream.str().c_str());
	}
}

void Resources::UnloadTexture2D(const string& _name)
{
	if (m_textures.contains(_name))
	{
		UnloadTexture(m_textures[_name]);
	}
}

void Resources::UnloadAll()
{
	for (const auto& val : m_textures | std::views::keys)
		UnloadTexture2D(val);
}