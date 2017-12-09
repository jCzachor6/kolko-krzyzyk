#pragma once

#include <memory>
#include <stack>
#include "State.hpp"

/**
 * @typedef	std::unique_ptr<State> StatePtr
 *
 * @brief	Defines an alias representing the current state pointer
 */
typedef std::unique_ptr<State> StatePtr;

/**
 * @class	GameStateManager
 *
 * @brief	Manager for game states.
 *
 * @author	Jakub Czachor
 * @date	04.12.2017
 */

class GameStateManager
{
public:

	/**
	 * @fn	void GameStateManager::AddState(StatePtr state, bool isReplacing = true);
	 *
	 * @brief	Manages the new state
	 *
	 * @param	state	   	The new state.
	 * @param	isReplacing	(Optional) True if this object is replacing.
	 */

	void AddState(StatePtr state, bool isReplacing = true);

	/**
	 * @fn	void GameStateManager::DeleteState();
	 *
	 * @brief	Deletes the state
	 */

	void DeleteState();

	/**
	 * @fn	void GameStateManager::ProcessStateChanges();
	 *
	 * @brief	Process the state changes on the beggining of game loop
	 */

	void ProcessStateChanges();

	/**
	 * @fn	StatePtr GameStateManager::&GetCurrentState();
	 *
	 * @brief	Gets current state
	 *
	 * @return	The current state.
	 */

	StatePtr &GetCurrentState();

private: 

	/**
	 * @property	std::stack <StatePtr> states
	 *
	 * @brief	Gets the states
	 *
	 * @return	The states.
	 */

	std::stack <StatePtr> states;
	/** @brief	Holds new state untill ProcessStateChanges() method is called */
	StatePtr newState;
	/** @brief	True if current state is deleted */
	bool isDeleting;
	/** @brief	True if new state is added */
	bool isAdding;
	/** @brief	True if new state replaces old one */
	bool isReplacing;
};

