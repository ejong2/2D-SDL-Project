#pragma once
#include "Actor.h"

class AEnemy : public AActor
{
public:
    AEnemy();
    AEnemy(int NewX, int NewY);
    ~AEnemy();

    virtual void Tick();
    bool PredictCanMove();

    Uint64 ElapsedTime = 0;
    Uint64 ExecuteTime = 0;
};

