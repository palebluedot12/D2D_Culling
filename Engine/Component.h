#pragma once
class GameObject;

class Component abstract // Ư���� ����� ���°� �ƴ϶� �߻��� ������ �ǹ�
{
private:
	GameObject* m_pOwner = nullptr; // �����ϰ� �ִ� ������Ʈ�� ���ϴ� ���� -> ��� ���ϱ�
public:
	Component();
	virtual ~Component();

	GameObject* GetOwner() { return m_pOwner; }
	void SetOwner(GameObject* pOwner) { m_pOwner = pOwner; }

	virtual void Update();
	virtual void Render();

};

