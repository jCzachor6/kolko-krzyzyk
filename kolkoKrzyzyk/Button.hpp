#pragma once

#include <SFML/Graphics.hpp>
#include "MainGame.hpp"
#include <functional>

/**
 * @fn	inline void defaultOnClick()
 *
 * @brief	Default on click
 *
 * @author	Jakub
 * @date	04.12.2017
 *
 * @exception	std::invalid_argument	default onClick function throws exception, to fix use setOnClick().
 */

inline void defaultOnClick() {
	throw std::invalid_argument("onClick method not initialized!");
}

/**
 * @class	Button
 *
 * @brief	A simple button.
 *
 * @author	Jakub Czachor
 * @date	04.12.2017
 */

class Button
{
public:

	/**
	 * @fn	Button::Button(GameDataPtr data, sf::Vector2i position, std::string notSelected, std::string selected);
	 *
	 * @brief	Constructor of Button
	 *
	 * @param	data	   	The data.
	 * @param	position   	The position.
	 * @param	notSelected	Name of resource of not selected button texture
	 * @param	selected   	Name of resource of selected button texture
	 */
	Button(GameDataPtr data, sf::Vector2i position, std::string notSelected, std::string selected);

	/**
	 * @fn	void Button::draw();
	 *
	 * @brief	Draws this object
	 *
	 */

	void draw();

	/**
	 * @fn	void Button::handleInput();
	 *
	 * @brief	Handles the input
	 *
	 */

	void handleInput();

	/**
	 * @fn	void Button::setOnClick(std::function<void()> onClick);
	 *
	 * @brief	Sets on click event
	 *
	 * @param	onClick	event
	 */

	void setOnClick(std::function<void()> onClick);
private:
	/** @brief	The game data */
	GameDataPtr data;
	/** @brief	The  button sprite */
	sf::Sprite sprite;
	/** @brief	Name of resource of not selected button texture */
	std::string notSelected;
	/** @brief	Name of resource of selected button texture */
	std::string selected;
	/** @brief	The on click event */
	std::function<void()> onClick;
};

