#include "pch.h"
#include "FiniteStateMachine.h"

FiniteStateMachine::FiniteStateMachine()
{
}

FiniteStateMachine::~FiniteStateMachine()
{
	for (std::pair<std::string, FSMState*> state: m_pStates)
	{
		delete state.second;
	}
}

void FiniteStateMachine::Update()
{
}

void FiniteStateMachine::SetPreState(std::string stateName)
{
}
