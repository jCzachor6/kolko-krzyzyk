#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"

class MenuState : public State
{
public:
	MenuState(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	int selectedSize;
	GameDataRef data;
	sf::Sprite backgroundSprite;
	sf::Sprite p10Sprite, p15Sprite, p20Sprite;
	sf::Sprite twoSprite, oneSprite, exitSprite;
};

