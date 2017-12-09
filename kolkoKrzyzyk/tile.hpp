#pragma once

#include <SFML/Graphics.hpp>
#include "MainGame.hpp"
#include <vector>

/**
 * @class	tile
 *
 * @brief	A tile of the board
 *
 * @author	Jakub
 * @date	04.12.2017
 */

class tile
{
public:

	/**
	 * @fn	tile::tile(GameDataPtr data, int x, int y);
	 *
	 * @brief	Constructor
	 *
	 * @param	data	The game data.
	 * @param	x   	The x position of tile.
	 * @param	y   	The y position of tile.
	 */

	tile(GameDataPtr data, int x, int y);

	/**
	 * @fn	void tile::drawTile();
	 *
	 * @brief	Draw tile
	 */

	void drawTile();

	/**
	 * @fn	void tile::setState(char state);
	 *
	 * @brief	Sets a state of a tile
	 *
	 * @param	state	The new state.
	 */

	void setState(char state);

	/**
	 * @fn	void tile::handleInput(bool *xTurn, bool *isChecked, sf::Event *ev);
	 *
	 * @brief	Handles the input of single tile
	 *
	 * @param [in,out]	xTurn	 	If non-null, true if X turn.
	 * @param [in,out]	isChecked	If non-null, true if this object is checked.
	 * @param [in,out]	ev		 	If non-null, the click event.
	 */

	void handleInput(bool *xTurn, bool *isChecked, sf::Event *ev);

	/**
	 * @fn	bool tile::isEmpty();
	 *
	 * @brief	Query if this object is 'e' state
	 *
	 * @return	True if empty, false if not.
	 */

	bool isEmpty();

	/**
	 * @fn	char tile::getState();
	 *
	 * @brief	Gets the current state of object
	 *
	 * @return	The state.
	 */

	char getState();
private:
	/** @brief	The game data */
	GameDataPtr data;
	/** @brief	The tile sprite */
	sf::Sprite sprite;
	/** @brief	The current state, default 'e'  */
	char state;
};

