#include "SplashState.hpp"
#include <sstream>
#include <iostream>
#include "MenuState.hpp"
#include "PlayState.hpp"

SplashState::SplashState(GameDataRef data)
{
	this->data = data;
}


void SplashState::Init()
{
	data->assetManager.LoadTexture("Splash_State_Background", "Resources/SplashState/splashScreen.png");
	backgroundSprite.setTexture(this->data->assetManager.GetTexture("Splash_State_Background"));
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

void SplashState::Update(float dt)
{
	if (clock.getElapsedTime().asSeconds() > 1.5) {
		data->stateManager.AddState(StateRef(new MenuState(this->data)));
	}
}

void SplashState::Draw(float dt)
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


