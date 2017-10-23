#pragma once

#include <memory>
#include <stack>
#include "State.hpp"

typedef std::unique_ptr<State> StatePtr;

class GameStateManager
{
public:
	GameStateManager() {};
	~GameStateManager() {};

	void AddState(StatePtr state, bool isReplacing = true);
	void DeleteState();
	void ProcessStateChanges();

	StatePtr &GetCurrentState();

private: 
	std::stack <StatePtr> states;
	StatePtr newState;
	bool isDeleting;
	bool isAdding;
	bool isReplacing;
};

