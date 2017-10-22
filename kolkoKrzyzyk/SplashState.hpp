#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"
#include "GridLayout.hpp"

class SplashState : public State
{
public:
	SplashState(GameDataRef data);
	void Init();
	void HandleInput();
	void Update();
	void Draw();
	void Remove();

private:
	GameDataRef data;
	GridLayout *gridLayout;
	sf::Clock clock;
	sf::Sprite backgroundSprite;
};

