#include "pch.h"
#include "World.h"

World::World()
{
}

World::~World()
{
}

void World::Update()
{
	for (GameObject*& obj : m_GameObjects)
	{
		obj->Update();
	}
}

void World::Render()
{
	count = 0;
	for (GameObject*& obj : m_GameObjects)
	{
		if (obj == mainCamera) continue; // 카메라는 카운트 하지 않는다
		if (mainCamera->m_BoundBox.CheckIntersect(obj->m_BoundBox)) // 카메라 바운드 박스와 다른 오브젝트의 바운드 박스가 겹치는지 체크
		{
			obj->Render();
			count++;
		}
	}
}

void World::Clear()
{
	m_GameObjects.clear();
}
