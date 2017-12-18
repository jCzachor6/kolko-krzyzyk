#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"
#include "Board.hpp"
#include "GridLayout.hpp"
#include "Button.hpp"

/**
 * @class	PlayState
 *
 * @brief	2 Players game state
 *
 * @author	Jakub
 * @date	04.12.2017
 */

class PlayState : public State
{
public:

	/**
	 * @fn	PlayState::PlayState(GameDataPtr data, int sizeX, int sizeY);
	 *
	 * @brief	Constructor
	 *
	 * @param	data 	The game data.
	 * @param	sizeX	The size x of board.
	 * @param	sizeY	The size y of board.
	 */

	PlayState(GameDataPtr data, int sizeX, int sizeY);

	/**
	 * @fn	void PlayState::Init();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Init();

	/**
	 * @fn	void PlayState::HandleInput();
	 *
	 * @brief	Check "State.hpp"
	 */

	void HandleInput();

	/**
	 * @fn	void PlayState::Update();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Update();

	/**
	 * @fn	void PlayState::Draw();
	 *
	 * @brief	Check "State.hpp"
	 */

	void Draw();

	/**
	 * @fn	void PlayState::Remove();
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
	/** @brief	The menu button, goes to Main Manu on click */
	Button *menuButton;

	/** @brief	True to turn for X */
	bool xTurn;
	/** @brief	Checks who won, 'e' if noone */
	char isWin;
	/** @brief	True to lock, false to unlock the input */
	bool lockInput;
};

