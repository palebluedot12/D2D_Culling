#pragma once
#include "GameObject.h"


class World
{
public:
	World();
	virtual ~World();

	std::list<GameObject*> m_GameObjects; // 게임 오브젝트 담기
	
	int count = 0; // 컬링되지 않고 카메라에 출력되는 오브젝트 수
	GameObject* mainCamera; // 게임 오브젝트 중 메인 카메라

public:
	void Update();
	void Render();
	void Clear();

	template<typename T>
	T* CreateGameObject()
	{
		bool bIsBase = std::is_base_of<GameObject, T>::value; // T는 GameObject를 상속받음
		assert(bIsBase == true);
		T* newObject = new T();
		newObject->SetOwner(this); // 생성된 객체의 소유자 설정, this는 CreateGameObject 함수가 속한 클래스의 인스턴스를 가리킴 -> 말이 어려워잉
		m_GameObjects.push_back(newObject);
		return newObject;
	}
};

