#include "Floor.h"

AFloor::AFloor()
{
	Shape = ' ';
}

AFloor::AFloor(int NewX, int NewY)
	: AFloor()
{
	X = NewX;
	Y = NewY;
}

AFloor::~AFloor()
{
}