#pragma once
#include "Engine\\GameObject.h"
class Stage :
	public GameObject
{
	Stage(GameObject* parent);
	~Stage();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	//int GrassBlock;
	//int SandBlock;
	//int StoneBlock;
	//int WaterBlock;
	//int WhiteBlock;
};

