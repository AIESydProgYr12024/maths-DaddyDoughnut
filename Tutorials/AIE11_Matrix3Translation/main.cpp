#include "AIE11Application.h"

int main()
{
	AIE11Application* app = new AIE11Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}