#pragma once

//미리 컴파일하려는 헤더 추가

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGH 800

#include <iostream>
#include "framework.h"
#include <Windows.h>

#include <d2d1.h>
#include <d2d1_1.h>
#pragma comment (lib,"d2d1")

#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "windowscodecs.lib")

#include <dxgi.h>
#include <dxgi1_4.h>
#include <d3d12.h>
#include <winerror.h>
#include <dwrite.h>

#include <d2d1helper.h>

#include <wincodec.h>
#include <comdef.h>
#include <string>
#include <vector>
#include <map>
#include <list>

#include <sstream>
#include <fstream>