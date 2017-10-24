#pragma once

#include <SFML/Graphics.hpp>
#include "MainGame.hpp"
#include <vector>

class tile
{
public:
	tile(GameDataPtr data, int x, int y);
	void drawTile();
	void setState(char state);
	void handleInput(bool *xTurn, bool *isChecked, sf::Event *ev);
	bool isEmpty();
	char getState();
private:
	GameDataPtr data;
	sf::Sprite sprite;
	char state;
};

