#include "Enemy.h"
#include "MyEngine.h"
#include "Player.h"
#include "Wall.h"
#include <iostream>

using namespace std;
 
AEnemy::AEnemy()
{
    srand((unsigned int)time(nullptr));
    Shape = 'M';
    ZOrder = 35;
    CollisionType = ECollisionType::QueryOnly;
    MyColor = { 255, 0, 255, 0 };

    ElapsedTime = 0;
    ExecuteTime = 500 + ((rand() % 200) - 100);
    LoadBMP("data/Slime.bmp");
}

AEnemy::AEnemy(int NewX, int NewY)
    :AEnemy()
{
    X = NewX;
    Y = NewY;
}

AEnemy::~AEnemy()
{

}

void AEnemy::Tick()
{

    for (AActor* Actor : GEngine->GetAllActors())
    {
        if (X == Actor->X && Y == Actor->Y &&
            dynamic_cast<APlayer*>(Actor))
        {
            cout << "Die !" << '\n';
            GEngine->QuitGame();
        }
    }

    ElapsedTime += GEngine->GetWorldDeltaSeconds();
    if (ExecuteTime > ElapsedTime)
    {
        return;
    }
    ElapsedTime = 0;

    int RandNum = rand() % 4;

    if (RandNum == 0)
    {
        X++;
        if (!PredictCanMove())
        {
            X--;
        }
    }
    else if (RandNum == 1)
    {
        X--;
        if (!PredictCanMove())
        {
            X++;
        }
    }
    else if (RandNum == 2)
    {
        Y--;
        if (!PredictCanMove())
        {
            Y++;
        }
    }
    else if (RandNum == 3)
    {
        Y++;
        if (!PredictCanMove())
        {
            Y--;
        }
    }
}

bool AEnemy::PredictCanMove()
{
    for (AActor* Actor : GEngine->GetAllActors())
    {
        if (X == Actor->X && Y == Actor->Y && dynamic_cast<AEnemy*>(Actor) == nullptr)
        {
            if (CheckHit(Actor))
            {
                return false;
            }
        }
    }
    return true;
}
