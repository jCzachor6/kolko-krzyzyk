#include "GameStateManager.hpp"


void ::GameStateManager::AddState(StateRef newState, bool isReplacing) {
	this->isAdding = true;
	this->isReplacing = isReplacing;
	this->newState = std::move(newState);
}

void GameStateManager::RemoveState(){
	this->isRemoving = true;
}

void GameStateManager::ProcessStateChanges() {
	if(this->isRemoving && !this->states.empty()) {
		this->states.pop();
		if (!this->states.empty()) {
			this->states.top()->Resume();
		}
		this->isRemoving = false;
	}
	if (this->isAdding) {
		if (!this->states.empty()) {
			if (this->isReplacing) {
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

StateRef & GameStateManager::GetActiveState()
{
	return this->states.top();
}
