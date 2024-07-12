#include "pch.h"
#include "CameraScene.h"
#include "GameObject.h"

void CameraScene::Update()
{
	__super::Update();
	m_CameraMatrix = m_WorldTransform
				   * D2D1::Matrix3x2F::Translation(-SCREEN_WIDTH * 0.5f, -SCREEN_HEIGH * 0.5);
	// 카메라의 바운드 박스
	GetOwner()->m_BoundBox.m_Extend.x = SCREEN_WIDTH * 0.5f;
	GetOwner()->m_BoundBox.m_Extend.y = SCREEN_HEIGH * 0.5f;

	// 카메라의 WorldTransform을 역행렬 -> 카메라의 이동과 오브젝트의 이동은 반대
	D2D1InvertMatrix(&m_CameraMatrix);

}
