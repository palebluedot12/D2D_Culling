#pragma once
#include "AnimationScene.h"
#include "CameraScene.h"
#include "AABB.h"

class Component;
class Scene;
class World;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	std::vector<Component*> m_OwnedComponents;		 // 소유한 컴포넌트들, 여러 개의 컴포넌트를 가질 수 있으니까
	Scene*					m_pRootScene = nullptr;	 // 하나의 오브젝트의 여러 컴포넌트 중 어떤 컴포넌트의 좌표 등을 따라갈지 결정할 때 필요
	World*					m_pOwner = nullptr;		 // 이 게임 오브젝트가 속한 월드(scene) 왜 포인터로 나타나져있을까?
	AABB					m_BoundBox;

	virtual void Update();
	virtual void Render();

	void SetRootScene(Scene* pRootComponent) { m_pRootScene = pRootComponent; }
	const AABB& GetBoundBox() const { return m_BoundBox; }
	void AddComponent(Component* pComponent);	// 사용할 컴포넌트를 추가
	void SetOwner(World* pOwner) { m_pOwner = pOwner; }
	D2D1_VECTOR_2F GetWorldLocation();

	template<typename T>
	T* CreateComponent()
	{
		bool bIsBase = std::is_base_of<Component, T>::value; // T는 Component를 상속받음
		assert(bIsBase == true);
		T* pComponent = new T();
		AddComponent(pComponent); //CreateComponent 하면 -> AddComponent해주기
		return pComponent;
	}
};

