#include "pch.h"
#include "ResourceManager.h"
#include "AnimationAsset.h"
#include "D2DRender.h"

ResourceManager* ResourceManager::pInstance;
std::map<std::wstring, ID2D1Bitmap*> ResourceManager::m_BitmapMap = {};
std::map<std::wstring, AnimationAsset*> ResourceManager::m_AnimationAssetMap = {};

ResourceManager::ResourceManager()
{
	ResourceManager::pInstance = this;
	m_BitmapMap.clear();
}

ResourceManager::~ResourceManager()
{
	assert(m_BitmapMap.empty());
	assert(m_AnimationAssetMap.empty());
}

bool ResourceManager::CreateD2DBitmapFromFile(std::wstring strFilePath, ID2D1Bitmap** bitmap)
{
	if (m_BitmapMap.find(strFilePath) != m_BitmapMap.end())
	{
		*bitmap = m_BitmapMap[strFilePath];
		(*bitmap)->AddRef();
		return true;
	}
	// ���� ���� ���� -> BitmapScene ���� ������

	HRESULT hr; // ����� �����ϴ� �����Ӵϴ�

	// �������̽��� �پ��� �̹��� ����(JPEG, PNG, BMP ��)�� �̹����� ���ڵ��Ͽ� �޸𸮿� �ε��� �� �ִ� ����� �����մϴ�.
	// �� ��ü�� ����Ͽ� �̹��� ������ �а�, �޸𸮿� ��Ʈ�� �������� ���ڵ��� �� �ֽ��ϴ�.
	IWICBitmapDecoder* pDecoder = NULL;

	// �������̽��� WIC���� �����ϴ� �پ��� �̹��� ���� ���� ��ȯ�� ����մϴ�.
	// �ַ� �̹����� ���� �����̳� ��Ʈ ���� ���� ��ȯ�� �� ���˴ϴ�.
	IWICFormatConverter* pConverter = NULL;

	hr = D2DRender::GetWICFactory()->CreateDecoderFromFilename(
		strFilePath.c_str(),             // Image to be decoded
		NULL,                            // Do not prefer a particular vendor
		GENERIC_READ,                    // Desired read access to the file
		WICDecodeMetadataCacheOnDemand,  // Cache metadata when needed
		&pDecoder                        // Pointer to the decoder
	);

	// WIC���� �̹����� �� �������� ���ڵ��ϱ� ���� ��ü�� ��Ÿ���ϴ�.
	// �̹��� ���˿� ���� �ϳ��� �̹����� ���� �������� ���� �� �ֽ��ϴ� (��: GIF �ִϸ��̼�).
	IWICBitmapFrameDecode* pFrame = NULL;
	if (SUCCEEDED(hr))
	{
		hr = pDecoder->GetFrame(0, &pFrame); // �� �κ� ���� ������ �������ֽÿɼҼ�
	}
	if (SUCCEEDED(hr))
	{
		hr = D2DRender::GetWICFactory()->CreateFormatConverter(&pConverter); // �� �κ� 
	}
	if (SUCCEEDED(hr))
	{
		hr = pConverter->Initialize(  // �̰� ���� �ǹ����� �ñ��մϴ� �Ф� �� �� �ʱ�ȭ
			pFrame,                          // Input bitmap to convert
			GUID_WICPixelFormat32bppPBGRA,   // Destination pixel format
			WICBitmapDitherTypeNone,         // Specified dither pattern
			NULL,                            // Specify a particular palette 
			0.f,                             // Alpha threshold
			WICBitmapPaletteTypeCustom       // Palette translation type
		);
	}

	if (SUCCEEDED(hr))
	{
		hr = D2DRender::GetRenderTarget()->CreateBitmapFromWicBitmap(pConverter, NULL, bitmap);

	}

	// ������ ����Ҷ����� �ٽ� �����.
	if (pConverter)
		pConverter->Release();

	if (pDecoder)
		pDecoder->Release();

	if (pFrame)
		pFrame->Release();


	m_BitmapMap[strFilePath] = *bitmap; // �� �̰� ����

	return true;
}

void ResourceManager::ReleaseD2DBitmap(std::wstring strFilePath)
{
	// Ű���� �����ϸ� ��Ʈ���� ��������
	if (m_BitmapMap.find(strFilePath) != m_BitmapMap.end())
	{
		ID2D1Bitmap* bitmap = m_BitmapMap[strFilePath];
		if (bitmap->Release() == 0)
		{
			m_BitmapMap.erase(m_BitmapMap.find(strFilePath));
		}
	}

}

bool ResourceManager::CreateAnimationAsset(std::wstring strFilePath, AnimationAsset** asset)
{
	if (m_AnimationAssetMap.find(strFilePath) != m_AnimationAssetMap.end())
	{
		*asset = m_AnimationAssetMap[strFilePath];
		(*asset)->AddRef();
		return true;
	}

	// �ִϸ��̼� ���� ���� -> �ִϸ��̼� ������ �ε�
	AnimationAsset* pTemp = new AnimationAsset;
	if (pTemp->LoadAnimation(strFilePath) == false)
	{
		delete pTemp;
		return false;
	}
	else
	{
		*asset = pTemp;
		(*asset)->AddRef();
	}
	m_AnimationAssetMap[strFilePath] = *asset;  //���ɳ�
	return true;

}

void ResourceManager::ReleaseAnimationAsset(std::wstring strFilePath)
{
	// Ű���� �����ϸ� ������ ��������
	if (m_AnimationAssetMap.find(strFilePath) != m_AnimationAssetMap.end())
	{
		AnimationAsset* asset = m_AnimationAssetMap[strFilePath];
		if (asset->Release() == 0)
		{
			m_AnimationAssetMap.erase(m_AnimationAssetMap.find(strFilePath));
		}
	}
}
