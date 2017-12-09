#include "AI.hpp"
#include "DEFINITIONS.hpp"

AI::AI()
{
	this->arePointsGenerated = false;
}

void AI::analyze(std::vector<std::vector<char>> tab)
{
	if (!arePointsGenerated) {
		generatePoints(tab.size());
		arePointsGenerated = true;
	}

	resetPointsToZero();

	for (int i = 0; i < tab.size(); i++) {
		for (int j = 0; j < tab.size(); j++) {
			if (tab.at(i).at(j) != 'e') {
				incHorizontaly(&tab, i, j);
				incHorizontalyBackwards(&tab, i, j);
				incVerticaly(&tab, i, j);
				incVerticalyBackwards(&tab, i, j);
				incDiagonalLeft(&tab, i, j);
				incDiagonalLeftBackwards(&tab, i, j);
				incDiagonalRight(&tab, i, j);
				incDiagonalRightBackwards(&tab, i, j);
			}
		}
	}

	setPointsToZeroOnXO(&tab);
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

void AI::resetPointsToZero()
{
	for (int i = 0; i < pointsOfInterest.size(); i++) {
		for (int j = 0; j < pointsOfInterest.size(); j++) {
			this->pointsOfInterest.at(i).at(j) = 0;
		}
	}
}

void AI::incHorizontaly(std::vector<std::vector<char>>* tab, int x, int y)
{
	int xCounter = 0;
	int i = y;
	try {
		for (; tab->at(x).at(i) == 'x'; i++) {
			xCounter++;
		}
		for (; xCounter>0; xCounter--) {
			if (tab->at(x).at(i) == 'o') break;
			pointsOfInterest.at(x).at(i) += xCounter;
			i++;
		}
	}
	catch (const std::out_of_range& oor) {}

	int oCounter = 0;
	i = y;
	try {
		for (; tab->at(x).at(i) == 'o'; i++) {
			oCounter++;
		}
		for (; oCounter>0; oCounter--) {
			if (tab->at(x).at(i) == 'x') break;
			pointsOfInterest.at(x).at(i) += oCounter;
			i++;
		}
	}
	catch (const std::out_of_range& oor) {}
}

void AI::incVerticaly(std::vector<std::vector<char>>* tab, int x, int y)
{
	int xCounter = 0;
	int i = x;
	try {
		for (; tab->at(i).at(y) == 'x'; i++) {
			xCounter++;
		}
		for (; xCounter>0; xCounter--) {
			if (tab->at(i).at(y) == 'o') break;
			pointsOfInterest.at(i).at(y) += xCounter;
			i++;	
		}
	}catch (const std::out_of_range& oor) {}

	int oCounter = 0;
	i = x;
	try {
		for (; tab->at(i).at(y) == 'o'; i++) {
			oCounter++;
		}
		for (; oCounter>0; oCounter--) {
			if (tab->at(i).at(y) == 'x') break;
			pointsOfInterest.at(i).at(y) += oCounter;
			i++;
		}
	}catch (const std::out_of_range& oor) {}
}

void AI::incDiagonalLeft(std::vector<std::vector<char>>* tab, int x, int y)
{
	int xCounter = 0;
	int i = x;
	int j = y;
	try {
		for (; tab->at(i).at(j) == 'x'; i++, j--) {
			xCounter++;
		}
		for (; xCounter>0; xCounter--) {
			if (tab->at(i).at(j) == 'o') break;
			pointsOfInterest.at(i).at(j) += xCounter;
			i++;
			j--;
		}
	}
	catch (const std::out_of_range& oor) {}

	int oCounter = 0;
	i = x;
	j = y;
	try {
		for (; tab->at(i).at(j) == 'o'; i++, j--) {
			oCounter++;
		}
		for (; oCounter>0; oCounter--) {
			if (tab->at(i).at(j) == 'x') break;
			pointsOfInterest.at(i).at(j) += oCounter;
			i++;
			j--;
		}
	}
	catch (const std::out_of_range& oor) {}
}

void AI::incDiagonalRight(std::vector<std::vector<char>>* tab, int x, int y)
{
	int xCounter = 0;
	int i = x;
	int j = y;
	try {
		for (; tab->at(i).at(j) == 'x'; i++, j++) {
			xCounter++;
		}
		for (; xCounter>0; xCounter--) {
			if (tab->at(i).at(j) == 'o') break;
			pointsOfInterest.at(i).at(j) += xCounter;
			i++;
			j++;
		}
	}
	catch (const std::out_of_range& oor) {}

	int oCounter = 0;
	i = x;
	j = y;
	try {
		for (; tab->at(i).at(j) == 'o'; i++, j++) {
			oCounter++;
		}
		for (; oCounter>0; oCounter--) {
			if (tab->at(i).at(j) == 'x') break;
			pointsOfInterest.at(i).at(j) += oCounter;
			i++;
			j++;
		}
	}
	catch (const std::out_of_range& oor) {}
}

void AI::incHorizontalyBackwards(std::vector<std::vector<char>>* tab, int x, int y)
{
	int xCounter = 0;
	int i = y;
	try {
		for (; tab->at(x).at(i) == 'x'; i--) {
			xCounter++;
		}
		for (; xCounter>0; xCounter--) {
			if (tab->at(x).at(i) == 'o') break;
			pointsOfInterest.at(x).at(i) += xCounter;
			i--;
		}
	}
	catch (const std::out_of_range& oor) {}

	int oCounter = 0;
	i = y;
	try {
		for (; tab->at(x).at(i) == 'o'; i--) {
			oCounter++;
		}
		for (; oCounter>0; oCounter--) {
			if (tab->at(x).at(i) == 'x') break;
			pointsOfInterest.at(x).at(i) += oCounter;
			i--;
		}
	}
	catch (const std::out_of_range& oor) {}
}

void AI::incVerticalyBackwards(std::vector<std::vector<char>>* tab, int x, int y)
{
	int xCounter = 0;
	int i = x;
	try {
		for (; tab->at(i).at(y) == 'x'; i--) {
			xCounter++;
		}
		for (; xCounter>0; xCounter--) {
			if (tab->at(i).at(y) == 'o') break;
			pointsOfInterest.at(i).at(y) += xCounter;
			i--;
		}
	}
	catch (const std::out_of_range& oor) {}

	int oCounter = 0;
	i = x;
	try {
		for (; tab->at(i).at(y) == 'o'; i--) {
			oCounter++;
		}
		for (; oCounter>0; oCounter--) {
			if (tab->at(i).at(y) == 'x') break;
			pointsOfInterest.at(i).at(y) += oCounter;
			i--;
		}
	}
	catch (const std::out_of_range& oor) {}
}

void AI::incDiagonalLeftBackwards(std::vector<std::vector<char>>* tab, int x, int y)
{
	int xCounter = 0;
	int i = x;
	int j = y;
	try {
		for (; tab->at(i).at(j) == 'x'; i--, j++) {
			xCounter++;
		}
		for (; xCounter>0; xCounter--) {
			if (tab->at(i).at(j) == 'o') break;
			pointsOfInterest.at(i).at(j) += xCounter;
			i--;
			j++;
		}
	}
	catch (const std::out_of_range& oor) {}

	int oCounter = 0;
	i = x;
	j = y;
	try {
		for (; tab->at(i).at(j) == 'o'; i--, j++) {
			oCounter++;
		}
		for (; oCounter>0; oCounter--) {
			if (tab->at(i).at(j) == 'x') break;
			pointsOfInterest.at(i).at(j) += oCounter;
			i--;
			j++;
		}
	}
	catch (const std::out_of_range& oor) {}
}

void AI::incDiagonalRightBackwards(std::vector<std::vector<char>>* tab, int x, int y)
{
	int xCounter = 0;
	int i = x;
	int j = y;
	try {
		for (; tab->at(i).at(j) == 'x'; i--, j--) {
			xCounter++;
		}
		for (; xCounter>0; xCounter--) {
			if (tab->at(i).at(j) == 'o') break;
			pointsOfInterest.at(i).at(j) += xCounter;
			i--;
			j--;
		}
	}
	catch (const std::out_of_range& oor) {}

	int oCounter = 0;
	i = x;
	j = y;
	try {
		for (; tab->at(i).at(j) == 'o'; i--, j--) {
			oCounter++;
		}
		for (; oCounter>0; oCounter--) {
			if (tab->at(i).at(j) == 'x') break;
			pointsOfInterest.at(i).at(j) += oCounter;
			i--;
			j--;
		}
	}
	catch (const std::out_of_range& oor) {}
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
