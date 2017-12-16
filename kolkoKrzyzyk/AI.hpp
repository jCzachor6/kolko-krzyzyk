#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include "MainGame.hpp"
#include "Board.hpp"

class AI
{
public:
	AI();
	void analyze(std::vector<std::vector<char>> tab);
	sf::Vector2i getHighestPoint();

	void findBotMove();
	void getValue_Position();
	int CheckValue(int xd, int yd, int vx, int vy, int pl);
	void make_a_move();


private:

};

