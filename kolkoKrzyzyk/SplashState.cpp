#include "SplashState.hpp"
#include <sstream>
#include <iostream>
#include "MenuState.hpp"
#include "PlayState.hpp"
#include "DEFINITIONS.hpp"

SplashState::SplashState(GameDataPtr data)
{
	this->data = data;
}


void SplashState::Init()
{
	data->assetManager.LoadTexture("Splash_State_Background", "Resources/SplashState/splashScreen.png");
	backgroundSprite.setTexture(this->data->assetManager.GetTexture("Splash_State_Background"));
	sf::Vector2f newScale(GAME_WIDTH / backgroundSprite.getGlobalBounds().width, GAME_HEIGHT / backgroundSprite.getLocalBounds().height);
	backgroundSprite.setScale(newScale);
}

void SplashState::HandleInput()
{
	sf::Event event;
	while (data->renderWindow.pollEvent(event)) {
		if (sf::Event::Closed == event.type) {
			data->renderWindow.close();
		}
	}
}

void SplashState::Update()
{
	if (clock.getElapsedTime().asSeconds() > 4) {
		data->stateManager.AddState(StatePtr(new MenuState(this->data)));
	}
}

void SplashState::Draw()
{
	data->renderWindow.clear();
	data->renderWindow.draw(backgroundSprite);
	data->renderWindow.display();
}

void SplashState::Remove()
{
	data->assetManager.RemoveTexture({ 
		"Splash_State_Background" 
	});
}


