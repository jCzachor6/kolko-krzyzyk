#pragma once
#include <SFML/Graphics.hpp>

/**
 * @class	InputManager
 *
 * @brief	Manager for inputs. Contains useful methods to maintain input.
 *
 * @author	Jakub Czachor
 * @date	04.12.2017
 */

class InputManager
{
public:

	/**
	 * @fn	bool InputManager::IsSpriteHold(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
	 *
	 * @brief	Checks if sprite is being held
	 *
	 * @param 		  	object	The checked sprite.
	 * @param 		  	button	The mouse button.
	 * @param [in,out]	window	The game window.
	 *
	 * @return	True if sprite is held, false if not.
	 */

	bool IsSpriteHold(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

	/**
	 * @fn	bool InputManager::IsSpritePressed(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window, sf::Event &ev);
	 *
	 * @brief	Checks if sprite is pressed
	 *
	 * @param 		  	object	The checked sprite.
	 * @param 		  	button	The mouse button.
	 * @param [in,out]	window	The game window.
	 * @param [in,out]	ev	  	The sfml event.
	 *
	 * @return	True if sprite pressed, false if not.
	 */

	bool IsSpritePressed(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window, sf::Event &ev);

	/**
	 * @fn	bool InputManager::IsMouseOnSprite(sf::Sprite object, sf::RenderWindow &window);
	 *
	 * @brief	Checks if mouse is over sprite
	 *
	 * @param 		  	object	The checked sprite.
	 * @param [in,out]	window	The game window.
	 *
	 * @return	True if mouse on sprite, false if not.
	 */

	bool IsMouseOnSprite(sf::Sprite object, sf::RenderWindow &window);

	/**
	 * @fn	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window);
	 *
	 * @brief	Gets mouse position
	 *
	 * @author	Jakub
	 * @date	04.12.2017
	 *
	 * @param [in,out]	window	The window.
	 *
	 * @return	The mouse position.
	 */

	sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};

