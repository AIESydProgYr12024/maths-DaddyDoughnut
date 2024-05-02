#pragma once

#include <raylib/raylib.h>

#include <map>
#include <string>

using std::map;
using std::string;

class Resources
{
public:
	static Texture2D* GetTexture(const string& _id);

	static void LoadTexture2D(const string& _name);
	static void UnloadTexture2D(const string& _name);
	static void UnloadAll();
private:
	static map<string, Texture2D> m_textures;
};

