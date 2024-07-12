#pragma once
#include "Scene.h"

class CameraScene : public Scene
{
public:

	D2D1_MATRIX_3X2_F m_CameraMatrix;

	virtual void Update();
};