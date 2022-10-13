#include "Player.h"
#include <iostream>

using namespace std;

APlayer::APlayer()
{
	Shape = 'P';
}

APlayer::APlayer(int NewX, int NewY)
	: APlayer()
{
	X = NewX;
	Y = NewY;
}

APlayer::~APlayer()
{
}

void APlayer::Input()
{
	cout << "Input" << endl;
}
