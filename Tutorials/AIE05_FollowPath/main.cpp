#include "AIE05Application.h"

int main()
{
	AIE05Application* app = new AIE05Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}