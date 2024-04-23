#include "AIE02Application.h"

int main()
{
	AIE02Application* app = new AIE02Application(720, 480, "Vector 2 Operators", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}