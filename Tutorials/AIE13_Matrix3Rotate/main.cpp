#include "AIE13Application.h"

int main()
{
	AIE13Application* app = new AIE13Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}