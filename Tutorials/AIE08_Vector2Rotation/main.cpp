#include "AIE08Application.h"

int main()
{
	AIE08Application* app = new AIE08Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}