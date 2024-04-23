#include "AIE07Application.h"

int main()
{
	AIE07Application* app = new AIE07Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}