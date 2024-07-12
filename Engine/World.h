#pragma once
#include "GameObject.h"


class World
{
public:
	World();
	virtual ~World();

	std::list<GameObject*> m_GameObjects; // ���� ������Ʈ ���
	
	int count = 0; // �ø����� �ʰ� ī�޶� ��µǴ� ������Ʈ ��
	GameObject* mainCamera; // ���� ������Ʈ �� ���� ī�޶�

public:
	void Update();
	void Render();
	void Clear();

	template<typename T>
	T* CreateGameObject()
	{
		bool bIsBase = std::is_base_of<GameObject, T>::value; // T�� GameObject�� ��ӹ���
		assert(bIsBase == true);
		T* newObject = new T();
		newObject->SetOwner(this); // ������ ��ü�� ������ ����, this�� CreateGameObject �Լ��� ���� Ŭ������ �ν��Ͻ��� ����Ŵ -> ���� �������
		m_GameObjects.push_back(newObject);
		return newObject;
	}
};

