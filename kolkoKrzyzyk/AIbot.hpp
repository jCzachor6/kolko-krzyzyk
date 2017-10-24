#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "MainGame.hpp"

class AIbot
{
public:
	AIbot(GameDataPtr data,  int difficulty);

	void analyze(std::vector<std::vector<char>> boardTiles);
	void adjustPointsToDifficulty();
	std::vector<sf::Vector2i> getBestPoints();
	void drawPointsOfInterest();

private:
	GameDataPtr data;
	int difficulty;
	void sortPoints();

	std::vector<std::vector<char>> pointsOfInterest;
	std::vector<sf::Vector2i> topPoints;
};

