#pragma once
#include <SFML/Graphics.hpp>

class GridLayout
{
public:
	GridLayout(int startX, int startY, int endX, int endY);
	void setRows(int horizontalRows, int verticalRows);
	sf::Vector2f getPosition(int vertRow, int horRow);
private:
	int startX;
	int startY;
	int endX;
	int endY;
	
	int horizontalRows;
	int verticalRows;
};

