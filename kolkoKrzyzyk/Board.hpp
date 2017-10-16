#pragma once
#include <SFML/Graphics.hpp>
#include "MainGame.hpp"
#include <vector>

class Board
{
public:
	Board(GameDataRef data, int size);
	void drawTiles();

private:
	GameDataRef data;
	std::vector<std::vector<sf::Sprite>> tilesSprites;
	int boardSize;
	void setupBoard();
};

