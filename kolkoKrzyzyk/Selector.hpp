#pragma once

#include <SFML/Graphics.hpp>
#include "MainGame.hpp"
#include <vector>
#include <string>



class Selector
{
public:
	Selector(GameDataRef data);
	~Selector();
	void addItem(sf::Vector2f pos, int returnValue, std::string notSelected, std::string selected);
	void handleInput();
	void draw();
	void setDefault();
	int getReturnValue();

private:
	GameDataRef data;

	class Item
	{
	public:
		sf::Sprite sprite;
		std::string notSelected;
		std::string selected;
		int returnValue;
	};

	std::vector<Item> items;
	int returnValue;


};

