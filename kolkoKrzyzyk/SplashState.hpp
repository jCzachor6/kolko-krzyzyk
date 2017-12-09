#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"
#include "GridLayout.hpp"

/**
 * @class	SplashState
 *
 * @brief	A splash state. First state, goes to main menu after some time.
 *
 * @author	Jakub
 * @date	04.12.2017
 */

class SplashState : public State
{
public:

	/**
	 * @fn	SplashState::SplashState(GameDataPtr data);
	 *
	 * @brief	Constructor
	 *
	 * @param	data	The game data.
	 */

	SplashState(GameDataPtr data);

	/**
	 * @fn	void SplashState::Init();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Init();

	/**
	 * @fn	void SplashState::HandleInput();
	 *
	 * @brief	Check "State.hpp"
	 */

	void HandleInput();

	/**
	 * @fn	void SplashState::Update();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Update();

	/**
	 * @fn	void SplashState::Draw();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Draw();

	/**
	 * @fn	void SplashState::Remove();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Remove();

private:
	/** @brief	The game data */
	GameDataPtr data;
	/** @brief	The grid layout */
	GridLayout *gridLayout;
	/** @brief	The SFML clock, used to count time after which go to menuState */
	sf::Clock clock;
	/** @brief	The background sprite */
	sf::Sprite backgroundSprite;
};

