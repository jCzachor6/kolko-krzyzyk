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
	setPointsToZero();
	incByOneAroundXO(&tab);
	setPointsToZeroOnXO(&tab);

	updateTexts();
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
	for (int i = 0; i < texts.size(); i++) {
		for (int j = 0; j < texts.size(); j++) {
			this->data->renderWindow.draw(texts.at(i).at(j));
		}
	}
}

sf::Vector2i AI::getHighestPoint()
{
	int max = 0;
	sf::Vector2i vec;
	for (int i = 0; i < pointsOfInterest.size(); i++) {
		for (int j = 0; j < pointsOfInterest.size(); j++) {
			if (max < pointsOfInterest.at(i).at(j)) {
				max = pointsOfInterest.at(i).at(j);
				vec.x = i;
				vec.y = j;
			}
		}
	}
	return vec;
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

void AI::setPointsToZero()
{
	for (int i = 0; i < texts.size(); i++) {
		for (int j = 0; j < texts.size(); j++) {
			this->pointsOfInterest.at(i).at(j) = 0;
		}
	}
}

void AI::incByOneAroundXO(std::vector<std::vector<char>> *tab)
{
	for (int i = 0; i < tab->size(); i++) {
		for (int j = 0; j < tab->size(); j++) {
			if (tab->at(i).at(j) == 'x' || tab->at(i).at(j) == 'o') {
				try{
				pointsOfInterest.at(i-1).at(j-1)++;
				}catch (const std::out_of_range& oor) {}
				try {
				pointsOfInterest.at(i).at(j-1)++;
				}catch (const std::out_of_range& oor) {}
				try {
				pointsOfInterest.at(i+1).at(j-1)++;
				}catch (const std::out_of_range& oor) {}
				try {
				pointsOfInterest.at(i-1).at(j)++;
				}catch (const std::out_of_range& oor) {}
				try {
				pointsOfInterest.at(i+1).at(j)++;
				}catch (const std::out_of_range& oor) {}
				try {
				pointsOfInterest.at(i-1).at(j+1)++;
				}catch (const std::out_of_range& oor) {}
				try {
				pointsOfInterest.at(i).at(j+1)++;
				}catch (const std::out_of_range& oor) {}
				try {
				pointsOfInterest.at(i+1).at(j+1)++;
				}catch (const std::out_of_range& oor) {}
			}
			
		}
	}
}

void AI::setPointsToZeroOnXO(std::vector<std::vector<char>> *tab)
{
	for (int i = 0; i < tab->size(); i++) {
		for (int j = 0; j < tab->size(); j++) {
			if (tab->at(i).at(j) == 'x' || tab->at(i).at(j) == 'o') {
				pointsOfInterest.at(i).at(j) = 0;
			}
		}
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
			text.setCharacterSize(18);
			text.setFillColor(sf::Color::Red);
			text.setPosition(initposX + 32 * j, initposY + 32 * i);
			Xrow.push_back(text);
		}
		texts.push_back(Xrow);
	}
}

void AI::updateTexts()
{
	for (int i = 0; i < pointsOfInterest.size(); i++) {
		for (int j = 0; j < pointsOfInterest.size(); j++) {
			texts.at(i).at(j).setString(std::to_string(pointsOfInterest.at(i).at(j)));
		}
	}
}

