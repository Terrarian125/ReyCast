//テストシーンにTest.FBXを
#include "TestScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Stage.h"
//#include "Test.h"

TestScene::TestScene(GameObject* parent)
	: GameObject(parent, "TestScene")
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
	// Testを生成して、子に追加  
	//Instanitiate<Test>(this);

	Instanitiate<Stage>(this);

	//Spriteオブジェクトを生成し、初期化する
	pBgSprite_ = new Sprite();
	pBgSprite_->Initialize();
}

void TestScene::Update()
{
	//スペースキーが押されたらPlaySceneに切り替え（SceneManager::ChangeScene(SCENE_ID_PLAY);を呼び出す）
	if (Input::IsKeyDown(DIK_SPACE))
	{
		GameObject* sceneManager = GetRootJob()->FindChildObject("SceneManager");
		if (sceneManager != nullptr)
		{
			static_cast<SceneManager*>(sceneManager)->ChangeScene(SCENE_ID_PLAY);
		}
	}

}

void TestScene::Draw()
{
	//背景スプライトを描画する
	//if (pBgSprite_ != nullptr)
	//{
	//	DirectX::XMMATRIX worldMatrix = DirectX::XMMatrixIdentity();
	//	pBgSprite_->Draw(worldMatrix);
	//}
}

void TestScene::Release()
{
	if (pBgSprite_ != nullptr)
	{
		pBgSprite_->Release();
		delete pBgSprite_;
		pBgSprite_ = nullptr;
	}
}
