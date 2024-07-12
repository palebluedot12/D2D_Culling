#pragma once
#include "ReferenceCounter.h"

struct FRAME_INFO
{
	D2D1_RECT_F		Source;   // �̹������� �ϳ��� ����� ��� ������ �ִ���
	D2D1_VECTOR_2F  Center;   // �ϳ��� FRAME���� ������� 0,0 ���� ������ ��ǥ
	FLOAT			Duration; // �ϳ��� ����� �׷����� �ð�

	// �ƹ� �μ� ���� ��ü�� ������ �� ���˴ϴ�.
	// ��� ������ �⺻��(��� 0)���� �ʱ�ȭ�մϴ�.
	FRAME_INFO()
	{
		Source.left = 0;
		Source.top = 0;
		Source.right = 0;
		Source.bottom = 0;
		Center.x = 0;
		Center.y = 0;
		Duration = 0;
	}

	// �̹��� ������ ��ǥ(left, top, right, bottom), �߽��� ��ǥ(centerX, centerY), ���� �ð�(time)�� ���������� �����Ͽ� ��ü�� ������ �� �ֽ��ϴ�.
	// ��ü ���� �� �ʿ��� ���� ���� �����Ͽ� �ʱ�ȭ�� �� �ֽ��ϴ�.
	FRAME_INFO(float left, float top, float right, float bottom, float centerX, float centerY, float time)
	{
		Source.left = left;
		Source.top = top;
		Source.right = right;
		Source.bottom = bottom;
		Center.x = centerX;
		Center.y = centerY;
		Duration = time;
	}

	FRAME_INFO(D2D1_RECT_F rect, float centerX, float centerY, float time)
	{
		Source = rect;
		Center.x = centerX;
		Center.y = centerY;
		Duration = time;
	}
};

struct ANIMATION_INFO // �ϳ��� ���ۿ� ���� ����
{
	std::string Name; // �ִϸ��̼� �̸�
	std::vector<FRAME_INFO> Frames; // �����ӵ��� �迭�̶�� ����
	bool Loop; // �ݺ� ����

	ANIMATION_INFO() : Name("Default") {}
};

// ���� ī��Ʈ�� �����Ͽ� 'AnimationAsset' ��ü�� ������ �����ϱ� ���� ���
class AnimationAsset : public ReferenceCounter
{
public:
	AnimationAsset() {};
	virtual ~AnimationAsset() {};

public:
	std::vector<ANIMATION_INFO> m_Animations; // �ִϸ��̼� ����

	ANIMATION_INFO* GetAnimation(int index)
	{
		// ������ false�� ���α׷� ����
		assert(index >= 0 && index < m_Animations.size());
		return &m_Animations[index];
	}
	ANIMATION_INFO* GetAnimation(std::string AnimationName)
	{
		// ���� �� ��� ��ȸ 
		for (auto& iter : m_Animations)
		{
			if (iter.Name == AnimationName)
			{
				return &iter;
			}
		}
	}

	bool LoadAnimation(std::wstring FilePath);
	bool LoadAnimationFromCSV(int index,const wchar_t* fileName);


};

