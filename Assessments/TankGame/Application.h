#pragma once

#include <raylib/raylib.h>

#include <string>

class Config;
class LevelManager;

using std::string;

class Application
{
public:
	Application();
	~Application();

public:
	void Run();
	void Quit();

	Config* GetConfig() const;

private:
	int m_width;
	int m_height;
	string m_title;

	bool m_running;
	Color m_clearColor;

	Config* m_config;
	LevelManager* m_levelManager;

private:
	void BeginPlay();

	void Tick(float _dt);
	void Render();

	void EndPlay();

	void LoadConfigValues();

};