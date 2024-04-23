#include "AIE03Application.h"

int main()
{
	AIE03Application* app = new AIE03Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}