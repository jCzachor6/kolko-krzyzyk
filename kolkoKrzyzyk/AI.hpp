#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "MainGame.hpp"
#include "Board.hpp"
#include <math.h>

/**
 * @class	AI
 *
 * @brief	An ai.
 *
 * @author	Jakub
 * @date	18.12.2017
 */

class AI
{
public:
	AI();

	/**
	 * @typedef	std::vector<std::vector<char>> charBoard
	 *
	 * @brief	Defines an alias representing the characters board
	 */

	typedef std::vector<std::vector<char>> charBoard;

	/**
	 * @typedef	std::vector<std::vector<double>> valBoard
	 *
	 * @brief	Defines an alias representing the double var board
	 */

	typedef std::vector<std::vector<double>> valBoard;

	/**
	 * @fn	sf::Vector2i AI::getNextStep(charBoard *states, char player);
	 *
	 * @brief	Gets the next step
	 *
	 * @param [in,out]	states	If non-null, the states.
	 * @param 		  	player	The player.
	 *
	 * @return	The next step.
	 */

	sf::Vector2i getNextStep(charBoard *states, char player);
private:

	/**
	 * @fn	void AI::findLine(sf::Vector2i pos, sf::Vector2i delta, char player, valBoard *board, charBoard *mainBoard, bool isBlocking);
	 *
	 * @brief	Searches for the first line
	 *
	 * @param 		  	pos		  	The position.
	 * @param 		  	delta	  	The delta position.
	 * @param 		  	player	  	The player.
	 * @param [in,out]	board	  	If non-null, the board.
	 * @param [in,out]	mainBoard 	If non-null, the main game board.
	 * @param 		  	isBlocking	True if this object is blocking.
	 */

	void findLine(sf::Vector2i pos, sf::Vector2i delta, char player, valBoard *board, charBoard *mainBoard, bool isBlocking);
	
};

