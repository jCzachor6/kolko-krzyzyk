#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"
#include "GridLayout.hpp"

class SplashState : public State
{
public:
	SplashState(GameDataPtr data);
	void Init();
	void HandleInput();
	void Update();
	void Draw();
	void Remove();

private:
	GameDataPtr data;
	GridLayout *gridLayout;
	sf::Clock clock;
	sf::Sprite backgroundSprite;
};

