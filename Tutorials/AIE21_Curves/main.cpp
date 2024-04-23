#include "AIE21Application.h"

int main()
{
	AIE21Application* app = new AIE21Application(720, 480, "Curves", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}