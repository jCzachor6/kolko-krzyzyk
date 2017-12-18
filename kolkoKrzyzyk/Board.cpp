#include "Board.hpp"
#include "DEFINITIONS.hpp"

Board::Board(GameDataPtr data, int sizeX, int sizeY)
{
	this->data = data;
	this->boardWidth = sizeX;
	this->boardHeight = sizeY;
	this->isChecked = true;
	setupBoard();
}

void Board::drawTiles()
{
	for (int i = 0; i < tilesVector.size(); i++) {
		for (int j = 0; j < tilesVector.at(i).size(); j++) {
			tilesVector.at(i).at(j).drawTile();
		}
	}
}

void Board::handleInput(bool *xTurn, sf::Event *ev)
{
	for (int i = 0; i < tilesVector.size(); i++) {
		for (int j = 0; j < tilesVector.at(i).size(); j++) {
			tilesVector.at(i).at(j).handleInput(xTurn, &isChecked, ev);
		}
	}
}

void Board::update(char *isWin)
{
	if (!isChecked) {
		isChecked = true;
		*isWin = checkIfWin();
	}
}

void Board::setPoint(sf::Vector2i point, char state)
{
	tilesVector.at(point.x).at(point.y).setState(state);
	isChecked = false;
}

std::vector<std::vector<char>> Board::getBoardTileStates()
{
	std::vector<std::vector<char>> charBoard;

	for (int i = 0; i < boardHeight; i++) {
		std::vector<char> Xrow;
		for (int j = 0; j < boardWidth; j++) {
			Xrow.push_back(tilesVector.at(i).at(j).getState());
		}
		charBoard.push_back(Xrow);
	}

	return charBoard;
}

sf::Vector2i Board::getBoardSize()
{
	return sf::Vector2i(boardWidth, boardHeight);
}

void Board::setupBoard()
{
	int initposX = 160;
	int initposY = 0;
	for (int i = 0; i < boardHeight; i++) {
		std::vector<tile> Xrow;
		for (int j = 0; j < boardWidth; j++) {
			tile tmpTile(this->data, initposX + 32 * j, initposY + 32 * i);
			Xrow.push_back(tmpTile);
		}
		tilesVector.push_back(Xrow);
	}
}

char Board::checkIfWin()
{
	int inRowToWin = IN_ROW_TO_WIN;
	int xRow = 0;
	int oRow = 0;
	for (int i = 0; i < tilesVector.size(); i++) {
		for (int j = 0; j < tilesVector.at(i).size(); j++) {
			switch (tilesVector.at(i).at(j).getState()) {
			case 'x':
				xRow++;
				oRow = 0;
				if (xRow == inRowToWin
					|| goBottom(j, i, 'x')
					|| goDiagonalLeft(j, i, 'x')
					|| goDiagonalRight(j, i, 'x'))
					return 'x';
				break;
			case 'o':
				oRow++;
				xRow = 0;
				if (oRow == inRowToWin
					|| goBottom(j, i, 'o')
					|| goDiagonalLeft(j, i, 'o')
					|| goDiagonalRight(j, i, 'o'))
					return 'o';
				break;
			default:
				xRow = 0;
				oRow = 0;
				break;
			}

		}
	}
	return 'e';
}

bool Board::goBottom(int x, int y, char state)
{
	int inRow = 0;
	if (y <= boardHeight - IN_ROW_TO_WIN) {
		for (int i = 0; i < IN_ROW_TO_WIN; i++) {
			if (tilesVector.at(y+i).at(x).getState() == state) {
				if (++inRow == IN_ROW_TO_WIN) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Board::goDiagonalLeft(int x, int y, char state)
{
	int inRow = 0;
	if (y <= boardHeight - IN_ROW_TO_WIN && x >= IN_ROW_TO_WIN-1) {
		for (int i = 0; i < IN_ROW_TO_WIN; i++) {
			if (tilesVector.at(y + i).at(x - i).getState() == state) {
				if (++inRow == IN_ROW_TO_WIN) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Board::goDiagonalRight(int x, int y, char state)
{
	int inRow = 0;
	if (y <= boardHeight - IN_ROW_TO_WIN && x <= boardHeight - IN_ROW_TO_WIN) {
		for (int i = 0; i < IN_ROW_TO_WIN; i++) {
			if (tilesVector.at(y + i).at(x + i).getState() == state) {
				if (++inRow == IN_ROW_TO_WIN) {
					return true;
				}
			}
		}
	}
	return false;
}


