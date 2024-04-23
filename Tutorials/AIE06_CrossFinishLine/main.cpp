#include "AIE06Application.h"

int main()
{
	AIE06Application* app = new AIE06Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}