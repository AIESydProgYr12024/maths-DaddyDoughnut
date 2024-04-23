#include "AIE10Application.h"

int main()
{
	AIE10Application* app = new AIE10Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}