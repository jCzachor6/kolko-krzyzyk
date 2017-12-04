#pragma once
#include <stack>

/**
 * @class	State
 *
 * @brief	Virtual State interface with methods to override.
 *
 * @author	Jakub
 * @date	04.12.2017
 */

class State
{
public:

	/**
	 * @fn	virtual void State::Init() = 0;
	 *
	 * @brief	Initializes the state, starts game loop
	 */

	virtual void Init() = 0;

	/**
	 * @fn	virtual void State::HandleInput() = 0;
	 *
	 * @brief	Handles the state input, inside game loop
	 */

	virtual void HandleInput() = 0;

	/**
	 * @fn	virtual void State::Update() = 0;
	 *
	 * @brief	Updates this state, inside game loop
	 */

	virtual void Update() = 0;

	/**
	 * @fn	virtual void State::Draw() = 0;
	 *
	 * @brief	Draws all sprites of this state, inside game loop
	 */

	virtual void Draw() = 0;

	/**
	 * @fn	virtual void State::Remove() = 0;
	 *
	 * @brief	Called on removal of state
	 */

	virtual void Remove() = 0;

	/**
	 * @fn	virtual void State::Pause()
	 *
	 * @brief	Called on pause of state, on default does nothing
	 */

	virtual void Pause() {};

	/**
	 * @fn	virtual void State::Resume()
	 *
	 * @brief	Called on resume of state, on default does nothing
	 */

	virtual void Resume() {};
};

