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
	sf::Vector2i getHighestPoint();

private:
	GameDataPtr data;
	int difficulty;
	std::string font;

	bool arePointsGenerated;

	void sortPoints();
	void generatePoints(int size);

	std::vector<std::vector<short>> pointsOfInterest;
	void setPointsToZero();
	void incByOneAroundXO(std::vector<std::vector<char>> *tab);
	void setPointsToZeroOnXO(std::vector<std::vector<char>> *tab);

	//draw 
	void setupTexts();
	void updateTexts();
	std::vector<std::vector<sf::Text>> texts;
};

