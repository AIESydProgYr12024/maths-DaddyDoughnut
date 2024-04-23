#include "AIE09Application.h"

int main()
{
	AIE09Application* app = new AIE09Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}