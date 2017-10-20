#pragma once

#include <SFML/Graphics.hpp>
#include "MainGame.hpp"
#include <vector>

class tile
{
public:
	tile(GameDataRef data, int x, int y);
	void drawTile();
	void setState(char state);
	void handleInput(bool *xTurn, bool *isChecked);
	bool isEmpty();
	char getState();
private:
	GameDataRef data;
	sf::Sprite sprite;
	char state;
};

