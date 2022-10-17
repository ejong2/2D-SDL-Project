

#pragma comment(lib, "SDL2.dll")
#pragma comment(lib, "SDL2.lib")

#include "MyEngine.h"

int SDL_main(int argc, char* argv[])
{
	GEngine->Initialize();

	GEngine->Run();

	GEngine->Terminalize();

	return 0;
}