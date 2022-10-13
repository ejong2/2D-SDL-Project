#pragma once
#include <string>

using namespace std;

class FWorld;

//추상 클래스
class Engine
{
public:
	Engine();
	virtual ~Engine();

	//순수 가상 함수
	virtual void Initialize() = 0;
	virtual void Terminalize() = 0;

	void Run();

protected:

	virtual void Input();
	virtual void Tick();
	virtual void Render();

	void Load(string MapFilename);

	FWorld* MyWorld;
};
