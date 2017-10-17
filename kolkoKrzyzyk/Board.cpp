#include "Board.hpp"
#include "DEFINITIONS.hpp"


Board::Board(GameDataRef data, int size)
{
	this->data = data;
	this->boardSize = size;
	setupBoard();
}

void Board::drawTiles()
{
	for (int i = 0; i < tilesVector.size(); i++) {
		for (int j = 0; j < tilesVector.size(); j++) {
			tilesVector.at(i).at(j).drawTile();
		}
	}
}

void Board::handleInput(bool *xTurn)
{
	for (int i = 0; i < tilesVector.size(); i++) {
		for (int j = 0; j < tilesVector.size(); j++) {
			tilesVector.at(i).at(j).handleInput(xTurn);
		}
	}
}

void Board::setupBoard()
{
	int initposX = (GAME_WIDTH / 2) - (32 * boardSize / 2);
	int initposY = (GAME_HEIGHT / 2) - (32 * boardSize / 2);
	for (int i = 0; i < boardSize; i++) {
		std::vector<tile> Xrow;
		for (int j = 0; j < boardSize; j++) {
			tile tmpTile(this->data, initposX + 32 * j, initposY + 32 * i);
			Xrow.push_back(tmpTile);
		}
		tilesVector.push_back(Xrow);
	}
}


