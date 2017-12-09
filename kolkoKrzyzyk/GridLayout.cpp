#include "GridLayout.hpp"



GridLayout::GridLayout(int startX, int startY, int endX, int endY)
{
	this->startX = startX;
	this->startY = startY;
	this->endX = endX;
	this->endY = endY;
	this->horizontalRows = 1;
	this->verticalRows = 1;
}


void GridLayout::setRows(int horizontalRows, int verticalRows)
{
	if (horizontalRows > 0 && verticalRows > 0) {
		this->horizontalRows = horizontalRows;
		this->verticalRows = verticalRows;
	}else throw std::invalid_argument("GridLayout received negative value");
}

sf::Vector2f GridLayout::getPosition(int vertRow, int horRow)
{
	int widthX = (endX - startX) / verticalRows;
	int widthY = (endY - startY) / horizontalRows;
	return sf::Vector2f(startX + widthX * vertRow, startY + widthY * horRow);
}

