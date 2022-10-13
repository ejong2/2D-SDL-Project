#include <iostream>
#include <fstream>
#include "MyEngine.h"

int main()
{
	MyEngine* E = new MyEngine();

	E->Initialize();

	E->Run();

	E->Terminalize();

	return 0;
}