#include "Application.h"

int main()
{
	Application* app = new Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}