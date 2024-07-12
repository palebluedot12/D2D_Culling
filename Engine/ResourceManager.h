#pragma once

class AnimationAsset;

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	static ResourceManager* pInstance; // 

	// std::wstring�� Ű��, ID2D1Bitmap*���� ����
	static std::map<std::wstring, ID2D1Bitmap*> m_BitmapMap;
	static std::map<std::wstring, AnimationAsset*> m_AnimationAssetMap;

	// bitmap ���ϵ��� �迭�� ����� �����մϴ�. -> ���ҽ�!!
	static bool CreateD2DBitmapFromFile(std::wstring strFilePath, ID2D1Bitmap** bitmap);
	static void ReleaseD2DBitmap(std::wstring strFilePath);

	// animation asset(������ ���� �ִϸ��̼ǵ�)�� �迭�� ����� �����մϴ�.
	static bool CreateAnimationAsset(std::wstring strFilePath, AnimationAsset** asset);
	static void ReleaseAnimationAsset(std::wstring strFilePath);
};

