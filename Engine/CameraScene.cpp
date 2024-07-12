#include "pch.h"
#include "CameraScene.h"
#include "GameObject.h"

void CameraScene::Update()
{
	__super::Update();
	m_CameraMatrix = m_WorldTransform
				   * D2D1::Matrix3x2F::Translation(-SCREEN_WIDTH * 0.5f, -SCREEN_HEIGH * 0.5);
	// ī�޶��� �ٿ�� �ڽ�
	GetOwner()->m_BoundBox.m_Extend.x = SCREEN_WIDTH * 0.5f;
	GetOwner()->m_BoundBox.m_Extend.y = SCREEN_HEIGH * 0.5f;

	// ī�޶��� WorldTransform�� ����� -> ī�޶��� �̵��� ������Ʈ�� �̵��� �ݴ�
	D2D1InvertMatrix(&m_CameraMatrix);

}
