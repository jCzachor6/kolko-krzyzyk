#pragma once
#include <SFML/Graphics.hpp>
#include "MainGame.hpp"
#include <vector>
#include "tile.hpp"
#include <iostream>

/**
 * @class	Board
 *
 * @brief	A board where all the x and o are placed
 *
 * @author	Jakub Czachor
 * @date	04.12.2017
 */

class Board
{
public:

	/**
	 * @fn	Board::Board(GameDataPtr data, int size);
	 *
	 * @brief	Constructor
	 *
	 * @param	data	The game data.
	 * @param	size	The size of the board.
	 */

	Board(GameDataPtr data, int sizeX, int sizeY);

	/**
	 * @fn	void Board::drawTiles();
	 *
	 * @brief	Draws all the tiles
	 */

	void drawTiles();

	/**
	 * @fn	void Board::handleInput(bool *xTurn, sf::Event *ev);
	 *
	 * @brief	Handles the input
	 * 			
	 * @param [in,out]	xTurn	Should change its state in case of placing new 'x' or 'y'
	 * @param [in,out]	ev   	If non-null, the ev.
	 */

	void handleInput(bool *xTurn, sf::Event *ev);

	/**
	 * @fn	void Board::update(char *isWin);
	 *
	 * @brief	Checks board if is win, changes isWin to:
	 * 			'e' if noone won
	 * 			'x' if x won
	 * 			'y' if y won
	 *
	 * @param [in,out]	isWin	If non-null, the is window.
	 */

	void update(char *isWin);

	/**
	 * @fn	void Board::setPoint(sf::Vector2i point, char state);
	 *
	 * @brief	Changes state of a tile to given in 2nd param 
	 *
	 * @param	point	The point.
	 * @param	state	The state.
	 */

	void setPoint(sf::Vector2i point, char state);

	/**
	 * @fn	std::vector<std::vector<char>> Board::getBoardTileStates();
	 *
	 * @brief	Returns board converted to squared array of char
	 *
	 * @return	The board tile states.
	 */

	 /**   
	 * @brief	The tiles squared vector   
	 */
	std::vector<std::vector<tile>> tilesVector;

	/**
	 * @fn	sf::Vector2i Board::getBoardSize();
	 *
	 * @brief	Gets board width and height
	 *
	 * @return	The board size.
	 */

	sf::Vector2i getBoardSize();

	/**
	 * @fn	std::vector<std::vector<char>> Board::getBoardTileStates();
	 *
	 * @brief	Gets board tile states
	 * 			'e' empty
	 * 			'x' x
	 * 			'y' y
	 *
	 * @return	The board tile states.
	 */

	std::vector<std::vector<char>> Board::getBoardTileStates();

private:
	/** @brief	The game data */
	GameDataPtr data;
	/** @brief	Width of the board */
	int boardWidth;
	/** @brief	Height of the board */
	int boardHeight;

	/**
	 * @fn	void Board::setupBoard();
	 *
	 * @brief	Sets up the board based on it's size
	 */

	void setupBoard();
	/** @brief	True if this object is checked */
	bool isChecked;

	/**
	 * @fn	char Board::checkIfWin();
	 *
	 * @brief	Check if game is won
	 *
	 * @return	A char.
	 */

	char checkIfWin();

	/**
	 * @fn	bool Board::goBottom(int x, int y, char state);
	 *
	 * @brief	Loop for checking for win
	 *
	 * @param	x	 	The x coordinate.
	 * @param	y	 	The y coordinate.
	 * @param	state	The state.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool goBottom(int x, int y, char state);

	/**
	 * @fn	bool Board::goDiagonalLeft(int x, int y, char state);
	 *
	 * @brief	Loop for checking for win
	 *
	 * @param	x	 	The x coordinate.
	 * @param	y	 	The y coordinate.
	 * @param	state	The state.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool goDiagonalLeft(int x, int y, char state);

	/**
	 * @fn	bool Board::goDiagonalRight(int x, int y, char state);
	 *
	 * @brief	Loop for checking for win
	 *
	 * @param	x	 	The x coordinate.
	 * @param	y	 	The y coordinate.
	 * @param	state	The state.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool goDiagonalRight(int x, int y, char state);
};

