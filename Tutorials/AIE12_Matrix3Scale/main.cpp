#include "AIE12Application.h"

int main()
{
	AIE12Application* app = new AIE12Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}