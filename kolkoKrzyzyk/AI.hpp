#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "MainGame.hpp"
#include "Board.hpp"
#include <math.h>

class AI
{
public:
	AI();
	typedef std::vector<std::vector<char>> charBoard;
	typedef std::vector<std::vector<double>> valBoard;
	sf::Vector2i getNextStep(charBoard *states, char player);
private:
	void findLine(sf::Vector2i pos, sf::Vector2i delta, char player, valBoard *board, charBoard *mainBoard, bool isBlocking);
	
};

