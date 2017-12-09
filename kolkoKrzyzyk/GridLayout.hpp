#pragma once
#include <SFML/Graphics.hpp>

/**
 * @class	GridLayout
 *
 * @brief	A grid layout used to divide screen into equal parts to
 * 			set item positions like on a grid
 *
 * @author	Jakub Czachor
 * @date	04.12.2017
 */

class GridLayout
{
public:

	/**
	 * @fn	GridLayout::GridLayout(int startX, int startY, int endX, int endY);
	 *
	 * @brief	Constructor
	 *
	 * @param	startX	The start x coordinate.
	 * @param	startY	The start y coordinate.
	 * @param	endX  	The end x coordinate.
	 * @param	endY  	The end y coordinate.
	 */

	GridLayout(int startX, int startY, int endX, int endY);

	/**
	 * @fn	void GridLayout::setRows(int horizontalRows, int verticalRows);
	 *
	 * @brief	Sets the number of rows in a grid
	 *
	 * @param	horizontalRows	The horizontal rows.
	 * @param	verticalRows  	The vertical rows.
	 */

	void setRows(int horizontalRows, int verticalRows);

	/**
	 * @fn	sf::Vector2f GridLayout::getPosition(int vertRow, int horRow);
	 *
	 * @brief	Gets a XY position based on amount of rows.
	 *
	 * @param	vertRow	The vertical row.
	 * @param	horRow 	The horizontal row.
	 *
	 * @return	The position based on vertical row and horizontal row.
	 */

	sf::Vector2f getPosition(int vertRow, int horRow);
private:
	/** @brief	The start x coordinate */
	int startX;
	/** @brief	The start y coordinate */
	int startY;
	/** @brief	The end x coordinate */
	int endX;
	/** @brief	The end y coordinate */
	int endY;
	
	/** @brief	The horizontal rows */
	int horizontalRows;
	/** @brief	The vertical rows */
	int verticalRows;
};

