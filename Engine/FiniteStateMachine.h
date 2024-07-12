#pragma once
#include "Component.h"`

class FSMState;

class FiniteStateMachine
	: public Component
{
public:
	FiniteStateMachine();
	~FiniteStateMachine();

protected:
	FSMState* m_pCurrState = nullptr;	// ���� ����
	FSMState* m_PreState = nullptr;		// ���� ����

	std::map<std::string, FSMState*> m_pStates; // ������ FSMState �����ϱ�

	void Update();
	void SetPreState(std::string stateName);

	template<typename T>
	void CreateState(const std::string StateName)
	{
		T* pState = new T(this, StateName);
		m_pStates.insert(std::make_pair(pState->GetName(), pState));
	}

};