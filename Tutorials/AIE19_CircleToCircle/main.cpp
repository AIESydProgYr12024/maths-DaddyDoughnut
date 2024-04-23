#include "AIE19Application.h"

int main()
{
	AIE19Application* app = new AIE19Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}