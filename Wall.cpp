#include "Wall.h"

AWall::AWall()
{
	Shape = '*';
}

AWall::AWall(int NewX, int NewY)
	: AWall()
{
	X = NewX;
	Y = NewY;
}

AWall::~AWall()
{
}