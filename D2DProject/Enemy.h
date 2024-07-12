#pragma once
#include "DemoApp.h"
#include "../Engine/AABB.h"
class Enemy
	: public GameObject
{

public:
	Enemy();
	~Enemy();

	void Update();
};