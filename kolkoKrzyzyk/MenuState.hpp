#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"
#include "Button.hpp"
#include "GridLayout.hpp"
#include "Selector.hpp"

class MenuState : public State
{
public:
	MenuState(GameDataRef data);
	~MenuState();
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	int selectedSize;
	GameDataRef data;
	sf::Sprite backgroundSprite;
	sf::Sprite p10Sprite, p15Sprite, p20Sprite;
	GridLayout *gridLayout;
	Button *twoPlayers;
	Button *onePlayer;
	Button *exitGame;
	Selector *boardSize;
};

