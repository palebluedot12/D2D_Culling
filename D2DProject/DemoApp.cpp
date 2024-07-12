#include "DemoApp.h"
#include "Player.h"
#include "Enemy.h"

void DemoApp::Initialize(HINSTANCE hInstance)
{
	__super::Initialize(hInstance);

	// 카메라 생성.
	GameObject* clone;
	clone = tempWorld.CreateGameObject<GameObject>();
	clone->m_pRootScene = clone->CreateComponent<CameraScene>();
	tempWorld.mainCamera = clone; // 메인카메라 설정 잊지말기!

	 //백그라운드 생성 -> 함수로 만들겠음
	clone = tempWorld.CreateGameObject<GameObject>();
	AnimationScene* Background = clone->CreateComponent<AnimationScene>();
	ResourceManager::pInstance->CreateD2DBitmapFromFile(L"Asset/midnight.png", &Background->m_pBitmap);
	ResourceManager::pInstance->CreateAnimationAsset(L"CSV/midnight.txt", &Background->m_pAnimationAsset);
	Background->SetAnimation(0, 0);
	clone->m_pRootScene = Background;
	
	// 적 생성
	clone = tempWorld.CreateGameObject<Enemy>();


	// 플레이어 생성
	clone = tempWorld.CreateGameObject<Player>();
}

void DemoApp::CheckKeyInput()
{
	InputManager KeyManager;

	if (KeyManager.IsKeyDown(VK_LEFT))
	{
		tempWorld.mainCamera->m_pRootScene->m_RelativeLocation.x -= 1;
	}
	if (KeyManager.IsKeyDown(VK_RIGHT))
	{
		tempWorld.mainCamera->m_pRootScene->m_RelativeLocation.x += 1;
	}
}

void DemoApp::PrintUsedVRAM()
{
	D2DRender::GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity());
	D2D1_RECT_F rect1 = { 0,0, 100,100 };
	std::wstring Vram = L"VRAM CHECK: " + std::to_wstring(D2DRender::GetUsedVRAM());
	D2DRender::GetRenderTarget()->DrawTextW(Vram.c_str(), static_cast<UINT32>(Vram.size()), D2DRender::GetIDWriteTextFormat(), rect1, D2DRender::GetID2D1SolidColorBrush());

	D2D1_RECT_F rect2 = { 0,50, 150,300 };
	std::wstring key = L"Create : C key, Release: R key, Reverse: <- key";
	D2DRender::GetRenderTarget()->DrawTextW(key.c_str(), static_cast<UINT32>(key.size()), D2DRender::GetIDWriteTextFormat(), rect2, D2DRender::GetID2D1SolidColorBrush());

	rect2 = { 0,150, 250,400 };
	key = L"Object count : " + std::to_wstring(tempWorld.count);
	D2DRender::GetRenderTarget()->DrawTextW(key.c_str(), static_cast<UINT32>(key.size()), D2DRender::GetIDWriteTextFormat(), rect2, D2DRender::GetID2D1SolidColorBrush());
}


void DemoApp::FixedUpdate()
{

}

void DemoApp::Update()
{
	CheckKeyInput();  
	tempWorld.Update();
}

 
void DemoApp::Render()
{
	D2DRender::GetRenderTarget()->BeginDraw();
	D2DRender::GetRenderTarget()->Clear(D2D1::ColorF(D2D1::ColorF::Black));
	tempWorld.Render();
	PrintUsedVRAM();
	D2DRender::GetRenderTarget()->EndDraw();
}
