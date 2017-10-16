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
	for (int i = 0; i < tilesSprites.size(); i++) {
		for (int j = 0; j < tilesSprites.size(); j++) {
			data->renderWindow.draw(tilesSprites.at(i).at(j));
		}
	}
}

void Board::setupBoard()
{
	int initposX = (GAME_WIDTH / 2) - (32 * boardSize / 2);
	int initposY = (GAME_HEIGHT / 2) - (32 * boardSize / 2);
	for (int i = 0; i < boardSize; i++) {
		std::vector<sf::Sprite> Xrow;
		for (int j = 0; j < boardSize; j++) {
			sf::Sprite tmp(data->assetManager.GetTextrure("tile_empty"));
			tmp.setPosition(initposX + 32*j, initposY + 32 * i);
			Xrow.push_back(tmp);
		}
		tilesSprites.push_back(Xrow);
	}
}


