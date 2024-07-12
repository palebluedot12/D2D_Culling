#pragma once
class D2DRender
{
private:
	// �������̽��� Direct2D ��ü���� �����ϰ�, ���ҽ��� �����ϸ�, ������ Ÿ���� ���� �� ���˴ϴ�.
	// Direct2D�� ����Ϸ��� ���� �� ���丮 ��ü�� �����ؾ� �մϴ�.
	static ID2D1Factory* m_pD2DFactory; 

	// �������̽��� ������ �ڵ�(HWND)�� ���� �׸� �� �ִ� ���� Ÿ���� ��Ÿ���ϴ�.
	// �̰��� ȭ�鿡 �׷����� �׸� �� �ִ� �ֿ� ��ü�Դϴ�.
	static ID2D1HwndRenderTarget* m_pRenderTarget;

	// �������̽��� Windows Imaging Component(WIC) ��ü���� �����ϰ� �̹����� �ε�, ���ڵ�, ���ڵ��ϴ� �� ���˴ϴ�.
	// �ַ� �̹��� ������ �а� ���� �۾��� �����մϴ�.
	static IWICImagingFactory* m_pWICFactory;


	// VRAM�� ����ϴ� ������ ����!
	static IDWriteFactory*		 m_pDWriteFactory;	// TextFormat������ ���� ���丮
	static IDWriteTextFormat*	 m_pDWriteTextFormat; // �⺻ �ؽ�Ʈ ����� ���� Format
	static IDXGIFactory4*		 m_pDXGIFactory;		// DXGI���丮
	static IDXGIAdapter3*		 m_pDXGIAdapter;		// ����ī�� ������ ���� ������ �������̽�
	static ID2D1SolidColorBrush* m_pBrush;	// ����Ÿ���� �����ϴ� ���ҽ� ���� ��ġ����

public:

	static BOOL InitDirect2D(HWND m_hWnd);
	static void Uninitialize();
	static size_t GetUsedVRAM();

	//getter -> �ٸ� ���Ͽ����� ���� �����ϰ� ����
	static ID2D1Factory* GetD2DFactor()					   { return m_pD2DFactory; }
	static ID2D1HwndRenderTarget* GetRenderTarget()		   { return m_pRenderTarget; }
	static IWICImagingFactory* GetWICFactory()			   { return m_pWICFactory; }
	static IDWriteTextFormat* GetIDWriteTextFormat()	   { return m_pDWriteTextFormat; }
	static ID2D1SolidColorBrush* GetID2D1SolidColorBrush() { return m_pBrush; }
};

