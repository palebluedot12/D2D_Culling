#include "pch.h"
#include "AnimationAsset.h"
#include "ResourceManager.h"


bool AnimationAsset::LoadAnimation(std::wstring FilePath)
{
	//�ؽ�Ʈ ������ ��� csv���� ����� �о�´�.
	// �Ʒ� �Լ��� csv������ ó���Ѵ�.
	if (FilePath == std::wstring(L"CSV/midnight.txt"))
	{
		// ����� CSV ����
		LoadAnimationFromCSV(0, L"CSV/midnight.txt");
	}
	if (FilePath == std::wstring(L"CSV/Run.txt"))
	{
		// �÷��̾��� CSV ����
		LoadAnimationFromCSV(1, L"CSV/Run.txt");
	}
	if (FilePath == std::wstring(L"CSV/KenIdle.txt"))
	{
		// ���� CSV ����
		LoadAnimationFromCSV(2, L"CSV/KenIdle.txt");
	}

	return true;
}


bool AnimationAsset::LoadAnimationFromCSV(int index, const wchar_t* fileName)
{
	std::wifstream file(fileName);
	if (!file.is_open())
	{
		return false;
	}

	std::wstring line;	// �� ���� ���ڿ�
	int FrameCount = 0;	// �������� ����
	{
		std::getline(file, line);	// ù��° �� �б�
		std::wstringstream wss(line);
		wss >> FrameCount;
	}

	m_Animations.resize(10);
	m_Animations[index].Frames.resize(FrameCount);
	for (int i = 0; i < FrameCount; i++)
	{
		std::getline(file, line);	 // ù��° �� �б�
		std::wstringstream wss(line); // �� �� �о wstringstream�� ����
		std::wstring token;
		{
			getline(wss, token, L',');	// wss�� ������ ,�� �������� ���ڿ��� �и�
			m_Animations[index].Frames[i].Source.left = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Source.top = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Source.right = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Source.bottom = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Center.x = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Center.y = (float)_wtoi(token.c_str());
			getline(wss, token, L',');
			m_Animations[index].Frames[i].Duration = _wtof(token.c_str());
		}
	}
}
