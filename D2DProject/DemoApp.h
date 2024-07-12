#pragma once
#include "../Engine/GameApp.h"


class DemoApp : public GameApp
{
public:

	World tempWorld;

	void Initialize(HINSTANCE hInstance);

	void CheckKeyInput();
	void PrintUsedVRAM();

	void FixedUpdate();
	void Update();
	void Render();
};

