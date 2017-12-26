#pragma once

#include <SFML/Graphics.hpp>
#include "MainGame.hpp"

/**
 * @class	Spinner
 *
 * @brief	A spinner. Select value between min and max 
 *
 * @author	Jakub
 * @date	09.12.2017
 */

class Spinner
{
public:

	/**
	 * @fn	Spinner::Spinner(GameDataPtr data, sf::Vector2f position, std::string notSelected, std::string selected, std::string font, int min, int max);
	 *
	 * @brief	Constructor
	 *
	 * @param	data	   	The game data.
	 * @param	position   	The spinner position.
	 * @param	notSelected	The not selected arrow texture string.
	 * @param	selected   	The selected arrow texture string.
	 * @param	font	   	The font of int value.
	 * @param	min		   	The minimum value.
	 * @param	max		   	The maximum value.
	 */

	Spinner(GameDataPtr data, sf::Vector2f position, std::string notSelected, std::string selected, std::string font, int min, int max);

	/**
	 * @fn	void Spinner::draw();
	 *
	 * @brief	Draws this object
	 */

	void draw();

	/**
	 * @fn	void Spinner::handleInput(sf::Event *ev);
	 *
	 * @brief	Handles the input described by ev
	 *
	 * @param [in,out]	ev	If non-null, the ev.
	 */

	void handleInput(sf::Event *ev);

	/**
	 * @fn	int Spinner::getValue();
	 *
	 * @brief	Gets the value
	 *
	 * @return	The selected value.
	 */

	int getValue();
private:
	/** @brief	The game data */
	GameDataPtr data;
	/** @brief	The top arrow sprite */
	sf::Sprite spriteTop;
	/** @brief	The bottom arrow sprite */
	sf::Sprite spriteBot;
	/** @brief	The not selected texture string */
	std::string notSelected;
	/** @brief	The selected texture string */
	std::string selected;
	/** @brief	The text value */
	sf::Text textValue;
	int value;
	/** @brief	The maximum value */
	int maxValue;
	/** @brief	The minimum value */
	int minValue;
};

