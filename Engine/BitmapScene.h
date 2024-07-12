#pragma once
#include "Scene.h"

class BitmapScene : public Scene
{
public:
	 std::wstring m_strFileName;
	 ID2D1Bitmap* m_pBitmap;
public:

	ID2D1Bitmap* GetBitmap() { return m_pBitmap; }

	// �޸𸮿��� ��Ʈ�� ������ ��
	
	//��Ʈ�� �ʱ�ȭ �Լ�
	bool SetBitmap(const std::wstring& strFileName);
	virtual void Update();
	virtual void Render();

	std::vector<Scene*> celList;
};