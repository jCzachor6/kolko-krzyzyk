#pragma once

#include <SFML/Graphics.hpp>
#include "MainGame.hpp"
#include <vector>
#include <string>

/**
 * @class	Selector
 *
 * @brief	Used to select between some int values
 *
 * @author	Jakub
 * @date	04.12.2017
 */

class Selector
{
public:

	/**
	 * @fn	Selector::Selector(GameDataPtr data);
	 *
	 * @brief	Constructors
	 *
	 * @param	data	The game data.
	 */
	Selector(GameDataPtr data);

	/**
	 * @fn	void Selector::addSelectable(sf::Vector2f pos, int returnValue, std::string notSelected, std::string selected);
	 *
	 * @brief	Adds a selectable
	 *
	 * @param	pos		   	The position.
	 * @param	returnValue	The return int value.
	 * @param	notSelected	Name of resource of not selected selectable texture
	 * @param	selected   	Name of resource of selected selectable texture
	 */

	void addSelectable(sf::Vector2f pos, int returnValue, std::string notSelected, std::string selected);

	/**
	 * @fn	void Selector::handleInput();
	 *
	 * @brief	Handles the input
	 */

	void handleInput();

	/**
	 * @fn	void Selector::draw();
	 *
	 * @brief	Draws all selectables
	 */

	void draw();

	/**
	 * @fn	void Selector::setDefault();
	 *
	 * @brief	Selects the first selectable
	 */

	void setDefault();

	/**
	 * @fn	int Selector::getReturnValue();
	 *
	 * @brief	Gets selected integer value
	 *
	 * @return	The return value.
	 */

	int getReturnValue();

private:
	/** @brief	The game data */
	GameDataPtr data;

	/**
	 * @struct	Selectable
	 *
	 * @brief	A selectable item.
	 *
	 * @author	Jakub
	 * @date	04.12.2017
	 */

	struct Selectable
	{
		/** @brief	The sprite */
		sf::Sprite sprite;
		/** @brief	The not selected */
		std::string notSelected;
		/** @brief	The selected */
		std::string selected;
		/** @brief	The return value */
		int returnValue;
	};

	/** @brief	Collection of selectable items */
	std::vector<Selectable> items;
	/** @brief	Current selected value */
	int returnValue;
};

