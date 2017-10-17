#pragma once
#include <SFML/Graphics.hpp>
#include "MainGame.hpp"
#include <vector>
#include "tile.hpp"

class Board
{
public:
	Board(GameDataRef data, int size);
	void drawTiles();
	void handleInput(bool *xTurn);
private:
	GameDataRef data;
	std::vector<std::vector<tile>> tilesVector;
	int boardSize;
	void setupBoard();
};

