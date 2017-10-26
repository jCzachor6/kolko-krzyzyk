#include "AI.hpp"
#include "DEFINITIONS.hpp"

AI::AI(GameDataPtr data, int difficulty, std::string font)
{
	this->data = data;
	this->difficulty = difficulty;
	this->arePointsGenerated = false;
	this->font = font;
}

void AI::analyze(std::vector<std::vector<char>> tab)
{
	if (!arePointsGenerated) {
		generatePoints(tab.size());
		setupTexts();
		arePointsGenerated = true;
	}
}

void AI::adjustPointsToDifficulty()
{
}

std::vector<sf::Vector2i> AI::getBestPoints()
{
	return std::vector<sf::Vector2i>();
}


void AI::drawPointsOfInterest()
{
	for (int i = 0; i < pointTexts.size(); i++) {
		for (int j = 0; j < pointTexts.size(); j++) {
			this->data->renderWindow.draw(pointTexts.at(i).at(j));
		}
	}
}

void AI::sortPoints()
{
}

void AI::generatePoints(int size)
{
	for (int i = 0; i < size; i++) {
		std::vector<short> Xrow;
		for (int j = 0; j < size; j++) {
			short num = 0;
			Xrow.push_back(num);
		}
		pointsOfInterest.push_back(Xrow);
	}
}

void AI::setupTexts()
{
	int initposX = (GAME_WIDTH / 2) - (32 * pointsOfInterest.size() / 2) + 8;
	int initposY = (GAME_HEIGHT / 2) - (32 * pointsOfInterest.size() / 2) + 3;
	for (int i = 0; i < pointsOfInterest.size(); i++) {
		std::vector<sf::Text> Xrow;
		for (int j = 0; j < pointsOfInterest.size(); j++) {
			sf::Text text;
			text.setFont(this->data->assetManager.GetFont(font));
			text.setString(std::to_string(0));
			text.setCharacterSize(20);
			text.setFillColor(sf::Color::Red);
			text.setPosition(initposX + 32 * j, initposY + 32 * i);
			Xrow.push_back(text);
		}
		pointTexts.push_back(Xrow);
	}
}

