#include "AIE16Application.h"

int main()
{
	AIE16Application* app = new AIE16Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}