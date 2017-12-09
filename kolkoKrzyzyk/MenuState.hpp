#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"
#include "Button.hpp"
#include "GridLayout.hpp"
#include "Spinner.hpp"

/**
 * @class	MenuState
 *
 * @brief	A menu state.
 *
 * @author	Jakub Czachor
 * @date	04.12.2017
 */

class MenuState : public State
{
public:

	/**
	 * @fn	MenuState::MenuState(GameDataPtr data);
	 *
	 * @brief	Constructor
	 *
	 * @param	data	The game data.
	 */

	MenuState(GameDataPtr data);

	/**
	 * @fn	void MenuState::Init();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Init();

	/**
	 * @fn	void MenuState::HandleInput();
	 *
	 * @brief	Check "State.hpp"
	 */

	void HandleInput();

	/**
	 * @fn	void MenuState::Update();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Update();

	/**
	 * @fn	void MenuState::Draw();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Draw();

	/**
	 * @fn	void MenuState::Remove();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Remove();

private:
	/** @brief	The game data */
	GameDataPtr data;
	/** @brief	The background sprite */
	sf::Sprite backgroundSprite;
	/** @brief	The grid layout */
	GridLayout *gridLayout;
	/** @brief	The two players button, runs PlayState on click */
	Button *twoPlayers;
	/** @brief	The one player button, runs PlayBotState on click*/
	Button *onePlayer;
	/** @brief	The exit game button */
	Button *exitGame;
	/** @brief	Selector of the board size Y*/
	Spinner *boardSizeY;
	/** @brief	Selector of the board size X*/
	Spinner *boardSizeX;
};

