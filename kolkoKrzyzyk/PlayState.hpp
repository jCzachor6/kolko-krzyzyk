#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"
#include "Board.hpp"
#include "GridLayout.hpp"
#include "Button.hpp"
#include "Selector.hpp"

class PlayState : public State
{
public:
	PlayState(GameDataRef data, int size);
	void Init();
	void HandleInput();
	void Update();
	void Draw();
	void Remove();

private:
	GameDataRef data;
	int board_size;
	sf::Clock clock;
	sf::Sprite backgroundSprite;
	sf::Sprite circleSprite;
	sf::Sprite crossSprite;
	sf::Sprite arrowSprite;
	sf::Sprite crownSprite;

	GridLayout *gridLayout;
	Board *board;
	Button *menuButton;

	bool xTurn;
	bool isWin;
	bool lockInput;
};

