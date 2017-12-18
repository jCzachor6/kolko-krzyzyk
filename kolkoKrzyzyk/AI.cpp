#include "AI.hpp"
#include "DEFINITIONS.hpp"

AI::AI()
{
	this->maxDepth = MINIMAX_DEPTH;
}

sf::Vector2i AI::getNextStep(charBoard *states, char player)
{
	sf::Vector2i bestPoint;
	minimax(states, player, 0, -AI::INF, AI::INF, true, &bestPoint);
	return bestPoint;
}

int AI::minimax(charBoard *states, char player, int depth, int alpha, int beta, bool isMaximize, sf::Vector2i *bestPoint)
{
	char enemyPlayer;
	if (player == 'x') enemyPlayer = 'o'; else enemyPlayer = 'x';

	sf::Vector2i dumpPoint;
	sf::Vector2i size(states->at(1).size(), states->size());
	
	if (depth >= this->maxDepth) {
		return this->computeScore(states, player);
	}

	charBoard *newBoard = new charBoard(*states);

	if (isMaximize) {
		int v = -AI::INF;
		for (int i = 0; i < size.y; i++) {
			for (int j = 0; j < size.x; j++) {
				if (states->at(i).at(j) == 'e') {
					newBoard->at(i).at(j) = player;
					int newV = this->minimax(newBoard, player, depth + 1, alpha, beta, false, &dumpPoint);
					if (v == -AI::INF || newV > v) {
						bestPoint->y = i; bestPoint->x = j;
					}
					if (newV > v) {
						v = newV;
					}
					alpha = std::max(alpha, v);
					newBoard->at(i).at(j) = 'e';
					if (beta <= alpha) break;
				}
			}
		}
		return v;
	}else {
		int v = AI::INF;
		for (int i = 0; i < size.y; i++) {
			for (int j = 0; j < size.x; j++) {
				if (states->at(i).at(j) == 'e') {
					newBoard->at(i).at(j) = enemyPlayer;
					int newV = this->minimax(newBoard, player, depth + 1, alpha, beta, true, &dumpPoint);
					if (v == AI::INF || newV < v) {
						bestPoint->y = i; bestPoint->x = j;
					}
					if (newV < v) {
						v = newV;
					}
					beta = std::min(beta, v);
					newBoard->at(i).at(j) = 'e';
					if (beta <= alpha) break;
				}
			}
		}
		return v;
	}

}

int AI::computeScore(charBoard *states, char player)
{
	int totalScore = 0;
	sf::Vector2i size(states->at(1).size(), states->size());
	for (int i = 0; i < size.y; i++) {
		for (int j = 0; j < size.x; j++) {
			sf::Vector2i pos(j, i);
			totalScore += this->computeVectorScore(states, player, pos, sf::Vector2i(0, 1));
			totalScore += this->computeVectorScore(states, player, pos, sf::Vector2i(1, 0));
			totalScore += this->computeVectorScore(states, player, pos, sf::Vector2i(1, 1));
			totalScore += this->computeVectorScore(states, player, pos, sf::Vector2i(-1, 1));
		}
	}
	return totalScore;
}

int AI::computeVectorScore(charBoard *states, char player, sf::Vector2i pos, sf::Vector2i delta)
{
	char enemyPlayer;
	if (player == 'x') enemyPlayer = 'o'; else enemyPlayer = 'x';
	sf::Vector2i size(states->at(1).size(), states->size());
	int countSelf = 0, countOpponent = 0;
	for (int k = 0; k < IN_ROW_TO_WIN; k++) {
		int ny = pos.y + delta.y * k;
		int nx = pos.x + delta.x * k;
		if (ny >= 0 && ny < size.y && nx >= 0 && nx < size.x) {
			if (player == states->at(ny).at(nx)) countSelf++;
			else if (enemyPlayer == states->at(ny).at(nx)) countOpponent++;
		}
		else {
			return 0;
		}
	}
	if (countSelf > 0 && countOpponent > 0) return 0;
	else if (countSelf > 0 && countOpponent == 0) return this->scoreVector[countSelf - 1];
	else if (countSelf == 0 && countOpponent > 0) return -this->scoreVector[countOpponent - 1];
	else return 0;
}



