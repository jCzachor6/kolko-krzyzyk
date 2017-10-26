#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "MainGame.hpp"

class AI
{
public:
	AI(GameDataPtr data,  int difficulty, std::string font);

	void analyze(std::vector<std::vector<char>> tab);
	void adjustPointsToDifficulty();
	std::vector<sf::Vector2i> getBestPoints();
	void drawPointsOfInterest();

private:
	GameDataPtr data;
	int difficulty;
	std::string font;

	void sortPoints();
	void generatePoints(int size);
	void setupTexts();

	std::vector<std::vector<short>> pointsOfInterest;
	std::vector<std::vector<sf::Text>> pointTexts;
	bool arePointsGenerated;

	std::vector<sf::Vector2i> topPoints;
};

