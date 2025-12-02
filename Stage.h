#pragma once
#include "Engine\\GameObject.h"
#include <vector>

namespace
{
	// ステージのサイズを定義する
	constexpr int XSIZE = 10;
	constexpr int ZSIZE = 10;
	constexpr int MAX_HEIGHT = 5; 
}

enum BLOCK_TYPE
{
	DEFAULT,
	WATER,
	SAND,
	GRASS,
	STONE,
	BLOCK_TYPE_MAX 
};

struct sDate
{
	BLOCK_TYPE type; // ブロックのタイプ
	int height; // ブロックを積む高さ
};

class Stage :
	public GameObject
{
public:
	void SetBlock(BLOCK_TYPE type, int x, int z) { sTable[z][x].type = type; } 
	void SetBlockHeight(int x, int z, int height) { sTable[z][x].height = height; } 
	sDate& GetT(int x, int z) { return sTable[z][x]; }
	const sDate& GetT_Const(int x, int z) const { return sTable[z][x]; } 

public:
	Stage(GameObject* parent);
	~Stage();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

private:
	sDate sTable[ZSIZE][XSIZE]; // 配列のサイズ
	int hModel[BLOCK_TYPE_MAX];
};