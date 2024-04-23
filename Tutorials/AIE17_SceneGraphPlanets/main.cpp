#include "AIE17Application.h"

int main()
{
	AIE17Application* app = new AIE17Application(720, 480, "Raylib Starter", RAYWHITE);

	app->Run();

	delete app;

	return 0;
}