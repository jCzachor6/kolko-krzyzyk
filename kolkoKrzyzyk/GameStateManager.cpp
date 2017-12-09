#include "GameStateManager.hpp"


void ::GameStateManager::AddState(StatePtr state, bool isReplacing) {
	this->isAdding = true;
	this->isReplacing = isReplacing;
	this->newState = std::move(state);
}

void GameStateManager::DeleteState(){
	this->isDeleting = true;
}

void GameStateManager::ProcessStateChanges() {
	if(this->isDeleting && !this->states.empty()) {
		this->states.top()->Remove();
		this->states.pop();
		if (!this->states.empty()) {
			this->states.top()->Resume();
		}
		this->isDeleting = false;
	}
	if (this->isAdding) {
		if (!this->states.empty()) {
			if (this->isReplacing) {
				this->states.top()->Remove();
				this->states.pop();
			}
			else {
				this->states.top()->Pause();
			}
		}
		this->states.push(std::move(this->newState));
		this->states.top()->Init();
		this->isAdding = false;
	}
}

StatePtr & GameStateManager::GetCurrentState()
{
	return this->states.top();
}
