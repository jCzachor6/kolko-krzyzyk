#include "AIbot.hpp"


AIbot::AIbot(GameDataPtr data, int difficulty)
{
	this->data = data;
	this->difficulty = difficulty;
}

void AIbot::analyze(std::vector<std::vector<char>> boardTiles)
{
}

void AIbot::adjustPointsToDifficulty()
{
}

std::vector<sf::Vector2i> AIbot::getBestPoints()
{
	return std::vector<sf::Vector2i>();
}


void AIbot::drawPointsOfInterest()
{
}

void AIbot::sortPoints()
{
}

