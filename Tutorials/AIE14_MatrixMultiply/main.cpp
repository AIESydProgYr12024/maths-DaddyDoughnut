#include "AIE14Application.h"

int main()
{
	AIE14Application* app = new AIE14Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}