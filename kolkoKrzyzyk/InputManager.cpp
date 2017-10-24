#include "InputManager.hpp"

bool InputManager::IsSpriteHold(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow & window)
{
	if (sf::Mouse::isButtonPressed(button)) {
			sf::IntRect tempRect(
				object.getPosition().x
				, object.getPosition().y
				, object.getGlobalBounds().width
				, object.getGlobalBounds().height);
			return (tempRect.contains(sf::Mouse::getPosition(window)));
	}
	return false;
}

bool InputManager::IsSpritePressed(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow & window, sf::Event & ev)
{
	sf::IntRect tempRect(
		object.getPosition().x
		, object.getPosition().y
		, object.getGlobalBounds().width
		, object.getGlobalBounds().height);

	if (ev.type == sf::Event::MouseButtonPressed && ev.key.code == button) {
		return (tempRect.contains(sf::Mouse::getPosition(window)));
	}
	return false;
}

bool InputManager::IsMouseOnSprite(sf::Sprite object, sf::RenderWindow & window)
{
	sf::IntRect tempRect(
		object.getPosition().x
		, object.getPosition().y
		, object.getGlobalBounds().width
		, object.getGlobalBounds().height);
	return tempRect.contains(sf::Mouse::getPosition(window));
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow & window)
{
	return sf::Mouse::getPosition(window);
}
