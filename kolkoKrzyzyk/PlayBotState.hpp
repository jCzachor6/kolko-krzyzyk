#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"
#include "Board.hpp"
#include "GridLayout.hpp"
#include "Button.hpp"
#include "AI.hpp"

/**
 * @class	PlayBotState
 *
 * @brief	Game versus AI
 *
 * @author	Jakub
 * @date	04.12.2017
 */

class PlayBotState : public State
{
public:

	/**
	 * @fn	PlayBotState::PlayBotState(GameDataPtr data, int size);
	 *
	 * @brief	Constructor
	 *
	 * @param	data	The game data.
	 * @param	size	The size of the board.
	 */

	PlayBotState(GameDataPtr data, int sizeX, int sizeY);

	/**
	 * @fn	void PlayBotState::Init();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Init();

	/**
	 * @fn	void PlayBotState::HandleInput();
	 *
	 * @brief	Check "State.hpp"
	 */

	void HandleInput();

	/**
	 * @fn	void PlayBotState::Update();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Update();

	/**
	 * @fn	void PlayBotState::Draw();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Draw();

	/**
	 * @fn	void PlayBotState::Remove();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Remove();

private:
	/** @brief	The game data */
	GameDataPtr data;
	/** @brief	Y Size of the board */
	int boardHeight;
	/** @brief	X Size of the board */
	int boardWidth;
	/** @brief	The background sprite */
	sf::Sprite backgroundSprite;
	/** @brief	The ai sprite */
	sf::Sprite aiSprite;
	/** @brief	The circle sprite */
	sf::Sprite circleSprite;
	/** @brief	The cross sprite */
	sf::Sprite crossSprite;
	/** @brief	The arrow sprite */
	sf::Sprite arrowSprite;
	/** @brief	The crown sprite */
	sf::Sprite crownSprite;

	/** @brief	The game board */
	Board *board;
	/** @brief	The menu button, gets to menu on click */
	Button *menuButton;

	/** @brief	True to turn for X */
	bool xTurn;
	/** @brief	Checks who won, 'e' if noone */
	char isWin;
	/** @brief	True to lock, false to unlock the input */
	bool lockInput;

	/** @brief	The in game AI */
	AI *bot;
};

