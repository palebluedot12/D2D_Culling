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

	std::vector<Component*> m_OwnedComponents;		 // ������ ������Ʈ��, ���� ���� ������Ʈ�� ���� �� �����ϱ�
	Scene*					m_pRootScene = nullptr;	 // �ϳ��� ������Ʈ�� ���� ������Ʈ �� � ������Ʈ�� ��ǥ ���� ������ ������ �� �ʿ�
	World*					m_pOwner = nullptr;		 // �� ���� ������Ʈ�� ���� ����(scene) �� �����ͷ� ��Ÿ����������?
	AABB					m_BoundBox;

	virtual void Update();
	virtual void Render();

	void SetRootScene(Scene* pRootComponent) { m_pRootScene = pRootComponent; }
	const AABB& GetBoundBox() const { return m_BoundBox; }
	void AddComponent(Component* pComponent);	// ����� ������Ʈ�� �߰�
	void SetOwner(World* pOwner) { m_pOwner = pOwner; }
	D2D1_VECTOR_2F GetWorldLocation();

	template<typename T>
	T* CreateComponent()
	{
		bool bIsBase = std::is_base_of<Component, T>::value; // T�� Component�� ��ӹ���
		assert(bIsBase == true);
		T* pComponent = new T();
		AddComponent(pComponent); //CreateComponent �ϸ� -> AddComponent���ֱ�
		return pComponent;
	}
};

