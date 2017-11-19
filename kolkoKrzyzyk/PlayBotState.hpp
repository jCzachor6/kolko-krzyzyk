#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"
#include "Board.hpp"
#include "GridLayout.hpp"
#include "Button.hpp"
#include "AI.hpp"

class PlayBotState : public State
{
public:
	PlayBotState(GameDataPtr data, int size, int difficulty);

	void Init();
	void HandleInput();
	void Update();
	void Draw();
	void Remove();

private:
	GameDataPtr data;
	int board_size;
	sf::Sprite backgroundSprite;
	sf::Sprite aiSprite;
	sf::Sprite circleSprite;
	sf::Sprite crossSprite;
	sf::Sprite arrowSprite;
	sf::Sprite crownSprite;

	GridLayout *gridLayout;
	Board *board;
	Button *menuButton;

	bool xTurn;
	char isWin;
	bool lockInput;

	int difficulty;
	AI *bot;
};

