#include "AIE04Application.h"

int main()
{
	AIE04Application* app = new AIE04Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}