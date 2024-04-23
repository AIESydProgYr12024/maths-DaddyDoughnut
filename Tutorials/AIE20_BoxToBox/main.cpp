#include "AIE20Application.h"

int main()
{
	AIE20Application* app = new AIE20Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}