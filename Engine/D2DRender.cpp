#include "pch.h"
#include "D2DRender.h"

ID2D1Factory*			D2DRender::m_pD2DFactory = nullptr;
ID2D1HwndRenderTarget*  D2DRender::m_pRenderTarget = nullptr;
IWICImagingFactory*	    D2DRender::m_pWICFactory = nullptr;

IDWriteFactory*			D2DRender::m_pDWriteFactory = nullptr;
IDWriteTextFormat*		D2DRender::m_pDWriteTextFormat = nullptr;
IDXGIFactory4*			D2DRender::m_pDXGIFactory = nullptr;
IDXGIAdapter3*			D2DRender::m_pDXGIAdapter = nullptr;
ID2D1SolidColorBrush*   D2DRender::m_pBrush = nullptr;

BOOL D2DRender::InitDirect2D(HWND m_hWnd)   
{
	HRESULT hr = S_OK;
	// COM 사용 시작
	hr = CoInitialize(NULL);
	if (SUCCEEDED(hr))
	{
		/*	장치에 바인딩되지 않은 리소스를 만듭니다.수명은 앱이 지속되는 동안 효과적으로 연장됩니다.
			이러한 리소스에는 Direct2D 및 DirectWrite 팩터리와
			DirectWrite 텍스트 형식 개체(특정 글꼴 특성을 식별하는 데 사용됨)가 포함됩니다.
		*/
		hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pD2DFactory);
	}
	if (SUCCEEDED(hr))
	{
		/*
		Direct3D 장치에 바인딩된 리소스를 만듭니다.
		Direct3D 장치가 손실된 경우(예: 디스플레이 변경, 원격, 비디오 카드 제거 등)
		리소스를 다시 생성해야 하는 경우를 대비하여 모두 여기에 중앙 집중화되어 있습니다.
		*/
		RECT rc;
		GetClientRect(m_hWnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(
			rc.right - rc.left,
			rc.bottom - rc.top);

		// Create a Direct2D render target.
		hr = m_pD2DFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(m_hWnd, size),
			&m_pRenderTarget);
	}

	if (SUCCEEDED(hr))
	{
		hr = m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &m_pBrush);
	}

	if (SUCCEEDED(hr))
	{
		// Create WIC factory
		hr = CoCreateInstance(
			CLSID_WICImagingFactory,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_PPV_ARGS(&m_pWICFactory)
		);
	}

	if (SUCCEEDED(hr))
	{
		// DirectWrite 팩터리를 만듭니다.
		hr = DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(m_pDWriteFactory),
			reinterpret_cast<IUnknown**>(&m_pDWriteFactory));
	}
	if (SUCCEEDED(hr))
	{
		// DirectWrite 텍스트 형식 개체를 만듭니다.
		hr = m_pDWriteFactory->CreateTextFormat(
			L"", // FontName    제어판-모든제어판-항목-글꼴-클릭 으로 글꼴이름 확인가능
			NULL,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			15.0f,   // Font Size
			L"", //locale
			&m_pDWriteTextFormat
		);
	}

	// VRAM 정보얻기 위한 개체 생성
	if (SUCCEEDED(hr))
	{
		// Create DXGI factory
		hr = CreateDXGIFactory1(__uuidof(IDXGIFactory4), (void**)&m_pDXGIFactory);
	}

	if (SUCCEEDED(hr))
	{
		m_pDXGIFactory->EnumAdapters(0, reinterpret_cast<IDXGIAdapter**>(&m_pDXGIAdapter));
	}

	return true;
}

void D2DRender::Uninitialize()
{
	if (m_pWICFactory)	 m_pWICFactory->Release();
	if (m_pRenderTarget) m_pRenderTarget->Release();
	if (m_pD2DFactory)	 m_pD2DFactory->Release();

	if (m_pDWriteFactory)	 m_pDWriteFactory->Release();
	if (m_pDWriteTextFormat) m_pDWriteTextFormat->Release();
	if (m_pDXGIFactory)		 m_pDXGIFactory->Release();
	if (m_pDXGIAdapter)		 m_pDXGIAdapter->Release();
		
	// COM 사용 끝
	CoUninitialize();
}

size_t D2DRender::GetUsedVRAM()
{
	DXGI_QUERY_VIDEO_MEMORY_INFO videoMemoryInfo;
	m_pDXGIAdapter->QueryVideoMemoryInfo(0, DXGI_MEMORY_SEGMENT_GROUP_LOCAL, &videoMemoryInfo);
	return videoMemoryInfo.CurrentUsage / 1024 / 1024;
}