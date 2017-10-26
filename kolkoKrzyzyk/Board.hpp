#pragma once
#include <SFML/Graphics.hpp>
#include "MainGame.hpp"
#include <vector>
#include "tile.hpp"
#include <iostream>

class Board
{
public:
	Board(GameDataPtr data, int size);
	void drawTiles();
	void handleInput(bool *xTurn, sf::Event *ev);
	void update(char *isWin);
	std::vector<std::vector<char>> getBoardTileStates();
private:
	GameDataPtr data;
	std::vector<std::vector<tile>> tilesVector;
	int boardSize;
	void setupBoard();
	bool isChecked;
	char checkIfWin();
	bool goBottom(int x, int y, char state);
	bool goDiagonalLeft(int x, int y, char state);
	bool goDiagonalRight(int x, int y, char state);
};

