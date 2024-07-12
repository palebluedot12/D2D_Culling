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
		if (obj == mainCamera) continue; // ī�޶�� ī��Ʈ ���� �ʴ´�
		if (mainCamera->m_BoundBox.CheckIntersect(obj->m_BoundBox)) // ī�޶� �ٿ�� �ڽ��� �ٸ� ������Ʈ�� �ٿ�� �ڽ��� ��ġ���� üũ
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
