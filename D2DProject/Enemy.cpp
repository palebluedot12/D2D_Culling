#include "Enemy.h"

Enemy::Enemy()
{
	AnimationScene* Enemy = GameObject::CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/ken.png", &Enemy->m_pBitmap);
	ResourceManager::pInstance->CreateAnimationAsset(L"CSV/KenIdle.txt", &Enemy->m_pAnimationAsset);
	Enemy->SetAnimation(2, 0);
	Enemy->m_RelativeLocation = { 400 ,200 };
	SetRootScene(Enemy);
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	__super::Update();

}
