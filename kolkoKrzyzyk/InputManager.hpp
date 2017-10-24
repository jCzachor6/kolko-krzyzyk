#pragma once
#include <SFML/Graphics.hpp>

class InputManager
{
public:
	InputManager() {};
	~InputManager(){}

	bool IsSpriteHold(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
	bool IsSpritePressed(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window, sf::Event &ev);
	bool IsMouseOnSprite(sf::Sprite object, sf::RenderWindow &window);
	sf::Vector2i GetMousePosition(sf::RenderWindow &window);
};

