#pragma once
#include "BitmapScene.h"
#include "AnimationAsset.h"
#include "D2DRender.h"
#include "ResourceManager.h"
#include "World.h"
#include "CameraScene.h"
#include "GameObject.h"

struct ANIMATION_INFO;

class AnimationScene 
	: public BitmapScene
{
public:
	AnimationScene();
	virtual ~AnimationScene();

	// �����ϴ� �ִϸ��̼� ����
	AnimationAsset* m_pAnimationAsset = nullptr;

	// �ν��Ͻ����� �ٸ� �ִϸ��̼� ����
	ANIMATION_INFO* m_pAnimationInfo = nullptr; // ���� �ִϸ��̼� ������ ����
	std::wstring	m_strAnimationAssetFilePath;  // �ִϸ��̼� ����, ���� �̸�
	
	
	float m_FrameTime = 0.0f;				   // ������ ���� �ð�
	int	  m_FrameIndexCurr = -1;			   // ���� ������ �ε���
	int	  m_FrameIndexPrev = -1;			   // ���� ������ �ε���
	int	  m_AnimationIndex = -1;			   // ���� �ִϸ��̼� �ε���
	D2D1_RECT_F m_SrcRect;					   // D2D1Bitmap�� Source ����
	D2D1_RECT_F m_DstRect;					   // RenderTarget�� Destination����

	bool m_bMirror;							   // �¿� ���� ����
	D2D1_MATRIX_3X2_F m_ImageTransform;         // �ݴ� �������� ������ ���� ��� Scale.x = -0.1f
	
	void LoadAnimationAsset(const std::wstring strFilePath);
	virtual void Update();
	void Render();
	void SetAnimation(int index, bool mirror);
};

