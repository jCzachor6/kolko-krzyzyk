#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MainGame.hpp"


class SplashState : public State
{
public:
	SplashState(GameDataRef data);
	~SplashState();
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef data;
	sf::Clock clock;
	sf::Sprite backgroundSprite;
};

