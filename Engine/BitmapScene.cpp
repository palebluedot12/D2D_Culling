#include "pch.h"
#include "BitmapScene.h"
#include "D2DRender.h";


bool BitmapScene::SetBitmap(const std::wstring& strFileName)
{
	//HRESULT hr; // ����� �����ϴ� �����Ӵϴ�

	//// �������̽��� �پ��� �̹��� ����(JPEG, PNG, BMP ��)�� �̹����� ���ڵ��Ͽ� �޸𸮿� �ε��� �� �ִ� ����� �����մϴ�.
	//// �� ��ü�� ����Ͽ� �̹��� ������ �а�, �޸𸮿� ��Ʈ�� �������� ���ڵ��� �� �ֽ��ϴ�.
	//IWICBitmapDecoder* pDecoder = NULL;

	//// �������̽��� WIC���� �����ϴ� �پ��� �̹��� ���� ���� ��ȯ�� ����մϴ�.
	//// �ַ� �̹����� ���� �����̳� ��Ʈ ���� ���� ��ȯ�� �� ���˴ϴ�.
	//IWICFormatConverter* pConverter = NULL;

	//hr = D2DRender::GetWICFactory()->CreateDecoderFromFilename(
	//	strFileName.c_str(),             // Image to be decoded
	//	NULL,                            // Do not prefer a particular vendor
	//	GENERIC_READ,                    // Desired read access to the file
	//	WICDecodeMetadataCacheOnDemand,  // Cache metadata when needed
	//	&pDecoder                        // Pointer to the decoder
	//);

	//// WIC���� �̹����� �� �������� ���ڵ��ϱ� ���� ��ü�� ��Ÿ���ϴ�.
	//// �̹��� ���˿� ���� �ϳ��� �̹����� ���� �������� ���� �� �ֽ��ϴ� (��: GIF �ִϸ��̼�).
	//IWICBitmapFrameDecode* pFrame = NULL;
	//if (SUCCEEDED(hr))
	//{
	//	hr = pDecoder->GetFrame(0, &pFrame); // �� �κ� ���� ������ �������ֽÿɼҼ�
	//}
	//if (SUCCEEDED(hr))
	//{
	//	hr = D2DRender::GetWICFactory()->CreateFormatConverter(&pConverter); // �� �κ� 
	//}
	//if (SUCCEEDED(hr))
	//{
	//	hr = pConverter->Initialize(  // �̰� ���� �ǹ����� �ñ��մϴ� �Ф� �� �� �ʱ�ȭ
	//		pFrame,                          // Input bitmap to convert
	//		GUID_WICPixelFormat32bppPBGRA,   // Destination pixel format
	//		WICBitmapDitherTypeNone,         // Specified dither pattern
	//		NULL,                            // Specify a particular palette 
	//		0.f,                             // Alpha threshold
	//		WICBitmapPaletteTypeCustom       // Palette translation type
	//	);
	//}

	//if (SUCCEEDED(hr))
	//{
	//	hr = D2DRender::GetRanderTarget()->CreateBitmapFromWicBitmap(pConverter, NULL, &m_pBitmap);

	//}


	//// ������ ����Ҷ����� �ٽ� �����.
	//if (pConverter)
	//	pConverter->Release();

	//if (pDecoder)
	//	pDecoder->Release();

	//if (pFrame)
	//	pFrame->Release();

	return false;
}


void BitmapScene::Update()
{
	__super::Update();
}

void BitmapScene::Render()
{
	D2D_SIZE_F size = m_pBitmap->GetSize();
	D2D_MATRIX_3X2_F center = D2D1::Matrix3x2F::Translation(size.width / 2, size.height / 2);
	D2D1InvertMatrix(&center);
	D2DRender::GetRenderTarget()->SetTransform(center * this->m_WorldTransform);
	D2DRender::GetRenderTarget()->DrawBitmap(this->m_pBitmap);
	D2DRender::GetRenderTarget()->SetTransform(D2D1::Matrix3x2F::Identity()); // ��ȯ �ʱ�ȭ
}