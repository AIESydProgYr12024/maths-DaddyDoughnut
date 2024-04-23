#include "AIE18Application.h"

int main()
{
	AIE18Application* app = new AIE18Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}