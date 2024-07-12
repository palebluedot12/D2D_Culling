#pragma once
class GameObject;

class Component abstract // 특별한 기능을 갖는게 아니라 추상적 개념을 의미
{
private:
	GameObject* m_pOwner = nullptr; // 소유하고 있는 오브젝트를 뜻하는 변수 -> 어디에 쓰일까
public:
	Component();
	virtual ~Component();

	GameObject* GetOwner() { return m_pOwner; }
	void SetOwner(GameObject* pOwner) { m_pOwner = pOwner; }

	virtual void Update();
	virtual void Render();

};

