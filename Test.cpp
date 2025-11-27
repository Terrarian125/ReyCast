#include "Test.h"
#include "Engine/Fbx.h"
//#include "ChildOden.h"
#include "Engine\\Model.h"

Test::Test(GameObject* parent)
	:GameObject(parent, "Test"), pFbx_(nullptr), hModel_(-1)
{
}

Test::~Test()
{
}

void Test::Initialize()
{
	//Fbx‚Ì¶¬‚Æ‰Šú‰»

	pFbx_ = new Fbx();
	pFbx_->Load("WaterBlock.fbx");
	transform_.scale_.x = 1.0f;
	transform_.scale_.y = 1.0f;
	transform_.scale_.z = 1.0f;

	hModel_ = Model::Load("WaterBlock.fbx");

	assert(hModel_ >= 0);

}

void Test::Update()
{
	transform_.rotate_.y += 0.4f;
}

void Test::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Test::Release()
{
	if (pFbx_) {
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}
}
