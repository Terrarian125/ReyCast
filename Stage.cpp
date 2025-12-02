#include "Stage.h"
#include <string>
#include <vector>
#include <cassert>
#include <iostream> // デバッグ/エラーチェック用（必須ではない）

// 仮のModelクラスとtransform構造体の定義（元のコードに定義がないため、コンパイルを通すために仮定）
// 実際には、"Engine\\GameObject.h"やその他のヘッダーで定義されているはずです。

struct transform
{
	struct Vector3 { float x, y, z; } position_, scale_, rotation_;
};

namespace Model
{
	int Load(const std::string& fileName) {
		static int nextHandle = 100;
		return nextHandle++;
	}
	void SetTransform(int hModel, const transform& t) {
		// モデルの変換を設定する処理
	}
	void Draw(int hModel) {
		// モデルを描画する処理
	}
	void Release(int hModel) {
		// モデルを解放する処理
	}
}

Stage::Stage(GameObject* parent)
	: GameObject(parent, "Stage")
{
	for (int z = 0; z < ZSIZE; ++z) {
		for (int x = 0; x < XSIZE; ++x) {
			sTable[z][x].type = DEFAULT;
			sTable[z][x].height = 0;
		}
	}
}

Stage::~Stage()
{
}

void Stage::Initialize()
{
	std::vector<std::string> modelName
	{
		"TestBlock.fbx", //
		"WaterBlock.fbx", //
		"SandBlock.fbx",  //
		"GrassBlock.fbx", //
		"StoneBlock.fbx", //
	};
	for (int i = 0; i < modelName.size(); i++) 
	{
		hModel[i] = Model::Load(modelName[i]);
		assert(hModel[i] >= 0);
	}
}

void Stage::Update()
{
//水の動きなどがあればここ?
}

void Stage::Draw()
{
	for (int z = 0; z < ZSIZE; z++) { 
		for (int x = 0; x < XSIZE; x++) 
		{

			const sDate& data = GetT_Const(x, z);

			int type = (int)data.type;
			if (type < 0 || type >= BLOCK_TYPE_MAX) {
				continue;
			}

			for (int k = 0; k < data.height; k++)
			{
				transform t;
				t.position_.x = (float)x;
				t.position_.z = (float)z;
				t.position_.y = (float)k;
				t.scale_.x = 1.0f;
				t.scale_.y = 1.0f;
				t.scale_.z = 1.0f;
				Model::SetTransform(hModel[type], t);
				Model::Draw(hModel[type]);
			}
		}
	}
}

void Stage::Release()
{
	// ロードしたモデルを解放
	for (int i = 0; i < BLOCK_TYPE_MAX; i++)
	{
		if (hModel[i] >= 0)
		{
			Model::Release(hModel[i]);
			hModel[i] = -1;
		}
	}
}