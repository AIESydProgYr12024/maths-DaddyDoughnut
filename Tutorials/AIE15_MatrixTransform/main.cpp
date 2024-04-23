#include "AIE15Application.h"

int main()
{
	AIE15Application* app = new AIE15Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}