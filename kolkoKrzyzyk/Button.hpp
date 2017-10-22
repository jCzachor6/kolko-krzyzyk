#pragma once

#include <SFML/Graphics.hpp>
#include "MainGame.hpp"
#include <functional>


//default onClick function throws exception, to fix use setOnClick()
inline void defaultOnClick() {
	throw std::invalid_argument("onClick method not initialized!");
}


class Button
{
public:
	Button(GameDataRef data, sf::Vector2i position, std::string notSelected, std::string selected);
	void draw();
	void handleInput();
	void setOnClick(std::function<void()> onClick);
private:
	GameDataRef data;
	sf::Sprite sprite;
	std::string notSelected;
	std::string selected;
	std::function<void()> onClick;
};

