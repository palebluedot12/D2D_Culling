#include "Player.h"

AnimationScene* Player::m_pPlayer = nullptr;

Player::Player()
{
	m_pPlayer = GameObject::CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/run.png", &m_pPlayer->m_pBitmap);
	ResourceManager::pInstance->CreateAnimationAsset(L"CSV/Run.txt", &m_pPlayer->m_pAnimationAsset);
	m_pPlayer->SetAnimation(1, 0);
	m_pPlayer->m_RelativeLocation = { 200 ,200 };
	SetRootScene(m_pPlayer);
}

void Player::PlayerMove() // state
{
	if (KeyManager.IsKeyDown('W'))
	{
		m_pRootScene->m_RelativeLocation.y -= 1;
	}
	if (KeyManager.IsKeyDown('A'))
	{
		m_pRootScene->m_RelativeLocation.x -= 1;
	}
	if (KeyManager.IsKeyDown('S'))
	{
		m_pRootScene->m_RelativeLocation.y += 1;
	}
	if (KeyManager.IsKeyDown('D'))
	{
		m_pRootScene->m_RelativeLocation.x += 1;
	}
}

void Player::Update()
{
	__super::Update();
	PlayerMove();
}
