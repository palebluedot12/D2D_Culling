#pragma once
class ReferenceCounter
{
private:

	unsigned int m_ReferenceCounter;

public:

	ReferenceCounter() : m_ReferenceCounter(0){}
	virtual ~ReferenceCounter() {}

	unsigned int AddRef()
	{
		m_ReferenceCounter++; // ���� ī��Ʈ 1 ���� -> ��ü�� ���� �� ������ �� �Լ� ȣ��

		return m_ReferenceCounter;
	}

	unsigned int Release()
	{
		m_ReferenceCounter--; // ���� ī��Ʈ 1 ���� -> ���� ī��Ʈ�� 0�� �Ǹ� delete this�� ȣ���Ͽ� ��ü ����
		if (m_ReferenceCounter == 0)
		{
			delete this; // �ڽ� Ŭ���� �Ҹ��� ȣ�� -> �θ� Ŭ���� �Ҹ��� ȣ�� ��
			return 0;
		}

		return m_ReferenceCounter;
	}

	unsigned int GetReferenceCount()
	{
		return m_ReferenceCounter; // ���� ��ü ���� ī��Ʈ ��ȯ
	}

};

