#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "MainGame.hpp"
#include "Board.hpp"

class AI
{
public:
	AI();
	typedef std::vector<std::vector<char>> charBoard;
	sf::Vector2i getNextStep(charBoard *states, char player);
private:
	static const int INF = 1 << 30;
	int maxDepth;
	int scoreVector[5] = { 1, 5, 25, 500, 10000 };

	int minimax(charBoard *states, char player, int depth, int alpha, int beta, bool isMaximize, sf::Vector2i *bestPoint);

	int computeScore(charBoard *states, char player);

	int computeVectorScore(charBoard *states, char player,  sf::Vector2i pos, sf::Vector2i delta);
};

