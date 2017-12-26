#include "AI.hpp"
#include "DEFINITIONS.hpp"

AI::AI()
{
}

sf::Vector2i AI::getNextStep(charBoard *states, char player)
{
	sf::Vector2i bestPoint;
	double max = -1;

	valBoard friendlyBoard(states->size(), std::vector<double>(states->at(1).size(), 0.0f));
	valBoard blockBoard(states->size(), std::vector<double>(states->at(1).size(), 0.0f));

	for (int y = 0; y < states->size(); y++) {
		for (int x = 0; x < states->at(1).size(); x++) {
				//NORTH
				findLine(sf::Vector2i(x, y), sf::Vector2i(0, -1), player, &friendlyBoard, states, false);
				//NORTH EAST
				findLine(sf::Vector2i(x, y), sf::Vector2i(1, -1), player, &friendlyBoard, states, false);
				//EAST
				findLine(sf::Vector2i(x, y), sf::Vector2i(1, 0), player, &friendlyBoard, states, false);
				//SOUTH EAST
				findLine(sf::Vector2i(x, y), sf::Vector2i(1, 1), player, &friendlyBoard, states, false);
				//SOUTH
				findLine(sf::Vector2i(x, y), sf::Vector2i(0, 1), player, &friendlyBoard, states, false);
				//SOUTH WEST
				findLine(sf::Vector2i(x, y), sf::Vector2i(-1, 1), player, &friendlyBoard, states, false);
				//WEST
				findLine(sf::Vector2i(x, y), sf::Vector2i(-1, 0), player, &friendlyBoard, states, false);
				//NORTH WEST
				findLine(sf::Vector2i(x, y), sf::Vector2i(-1, -1), player, &friendlyBoard, states, false);

				char enemy;
				if (player == 'x') enemy = 'o';
				else enemy = 'x';

				//NORTH
				findLine(sf::Vector2i(x, y), sf::Vector2i(0, -1), enemy, &blockBoard, states, true);
				//NORTH EAST
				findLine(sf::Vector2i(x, y), sf::Vector2i(1, -1), enemy, &blockBoard, states, true);
				//EAST
				findLine(sf::Vector2i(x, y), sf::Vector2i(1, 0), enemy, &blockBoard, states, true);
				//SOUTH EAST
				findLine(sf::Vector2i(x, y), sf::Vector2i(1, 1), enemy, &blockBoard, states, true);
				//SOUTH
				findLine(sf::Vector2i(x, y), sf::Vector2i(0, 1), enemy, &blockBoard, states, true);
				//SOUTH WEST
				findLine(sf::Vector2i(x, y), sf::Vector2i(-1, 1), enemy, &blockBoard, states, true);
				//WEST
				findLine(sf::Vector2i(x, y), sf::Vector2i(-1, 0), enemy, &blockBoard, states, true);
				//NORTH WEST
				findLine(sf::Vector2i(x, y), sf::Vector2i(-1, -1), enemy, &blockBoard, states, true);

		}
	}
	valBoard sumBoard(states->size(), std::vector<double>(states->at(1).size(), 0.0f));

	for (int y = 0; y < states->size(); y++) {
		for (int x = 0; x < states->at(1).size(); x++) {
			sumBoard.at(y).at(x) = friendlyBoard.at(y).at(x) + blockBoard.at(y).at(x);
		}
	}



	for (int y = 0; y < states->size(); y++) {
		for (int x = 0; x < states->at(1).size(); x++) {
			if (max <= sumBoard.at(y).at(x)) {
				max = sumBoard.at(y).at(x);
				bestPoint = sf::Vector2i(y, x);
			}
		}
	}

	return bestPoint;
}

void AI::findLine(sf::Vector2i pos, sf::Vector2i delta, char player, valBoard * board, charBoard * mainBoard, bool isBlocking)
{
	int friendlyNum = 0;

	for (int i = 0; i < IN_ROW_TO_WIN; i++) {
		sf::Vector2i tmp(pos.x + i*delta.x, pos.y + i * delta.y);	
		if (tmp.x >= mainBoard->at(1).size() 
			|| tmp.y >= mainBoard->size()
			|| tmp.x < 0 
			|| tmp.y < 0) {
			break;
		}
		char state = mainBoard->at(tmp.y).at(tmp.x);
		if (state != player && state != 'e') {
			break;
		}
		if (state == player) {
			friendlyNum++;
		}
	}
	for (int i = 0; i < IN_ROW_TO_WIN; i++) {
		sf::Vector2i tmp(pos.x + i*delta.x, pos.y + i * delta.y);
		if (tmp.x >= mainBoard->at(1).size()
			|| tmp.y >= mainBoard->size()
			|| tmp.x < 0
			|| tmp.y < 0) {
			break;
		}
		char state = mainBoard->at(tmp.y).at(tmp.x);
		if (state == 'e') {
			double score = pow(friendlyNum, IN_ROW_TO_WIN/2)/2;
			board->at(tmp.y).at(tmp.x) += score;

			if (friendlyNum >= 4) {
				int crucialMove = 100;
				if (isBlocking == false) {
					crucialMove += 200;
				}
				board->at(tmp.y).at(tmp.x) += crucialMove;
			}
		}
	}
}

