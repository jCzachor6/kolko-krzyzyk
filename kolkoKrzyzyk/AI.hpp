#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "MainGame.hpp"
#include "Board.hpp"

class AI
{
public:
	AI();

	void analyze(std::vector<std::vector<char>> tab);
	std::vector<sf::Vector2i> getBestPoints();
	sf::Vector2i getHighestPoint();

private:
	bool arePointsGenerated;
	void generatePoints(int size);

	std::vector<std::vector<short>> pointsOfInterest;
	void resetPointsToZero();

	void incHorizontaly(std::vector<std::vector<char>> *tab, int x, int y);
	void incVerticaly(std::vector<std::vector<char>> *tab, int x, int y);
	void incDiagonalLeft(std::vector<std::vector<char>> *tab, int x, int y);
	void incDiagonalRight(std::vector<std::vector<char>> *tab, int x, int y);

	void incHorizontalyBackwards(std::vector<std::vector<char>> *tab, int x, int y);
	void incVerticalyBackwards(std::vector<std::vector<char>> *tab, int x, int y);
	void incDiagonalLeftBackwards(std::vector<std::vector<char>> *tab, int x, int y);
	void incDiagonalRightBackwards(std::vector<std::vector<char>> *tab, int x, int y);
	
	void setPointsToZeroOnXO(std::vector<std::vector<char>> *tab);
};

