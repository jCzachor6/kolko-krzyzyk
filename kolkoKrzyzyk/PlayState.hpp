#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"
#include "Board.hpp"

class PlayState : public State
{
public:
	PlayState(GameDataRef data, int size);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef data;
	int board_size;
	sf::Clock clock;
	sf::Sprite backgroundSprite;
	Board *board;
};

