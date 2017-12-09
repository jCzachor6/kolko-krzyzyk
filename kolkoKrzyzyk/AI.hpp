#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "MainGame.hpp"
#include "Board.hpp"

/**
 * @class	AI
 *
 * @brief	In game AI
 * 				 
 * @author	Jakub Czachor
 * @date	04.12.2017
 */

class AI
{
public:
	AI();

	/**
	 * @fn	void AI::analyze(std::vector<std::vector<char>> tab);
	 *
	 * @brief	Analyzes the given squared array of char
	 * 			'e' - empty
	 * 			'x' - x placed
	 *			'y' - y placed
	 * @param	squared array of char
	 */

	void analyze(std::vector<std::vector<char>> tab);

	/**
	 * @fn	sf::Vector2i AI::getHighestPoint();
	 *
	 * @brief	Gets position of highest point from pointsOfInterest array
	 *
	 * @return	The highest point.
	 */

	sf::Vector2i getHighestPoint();

private:
	bool arePointsGenerated;
	void generatePoints(int size);

	std::vector<std::vector<short>> pointsOfInterest;
	void resetPointsToZero();

	void incHorizontaly(std::vector<std::vector<char>> *tab, int x, int y);
	void incVerticaly(std::vector<std::vector<char>> *tab, int x, int y);
	void incDiagonalLeft(std::vector<std::vector<char>> *tab, int x, int y);
	void incDiagonalRight(std::vector<std::vector<char>> *tab, int x, int y);

	void incHorizontalyBackwards(std::vector<std::vector<char>> *tab, int x, int y);
	void incVerticalyBackwards(std::vector<std::vector<char>> *tab, int x, int y);
	void incDiagonalLeftBackwards(std::vector<std::vector<char>> *tab, int x, int y);
	void incDiagonalRightBackwards(std::vector<std::vector<char>> *tab, int x, int y);
	
	void setPointsToZeroOnXO(std::vector<std::vector<char>> *tab);
};

