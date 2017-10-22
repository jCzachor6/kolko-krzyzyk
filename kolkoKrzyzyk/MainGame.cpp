#include "MainGame.hpp"
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"

MainGame::MainGame(int width, int height, std::string title)
{
	data->renderWindow.create(sf::VideoMode(width, height), title, sf::Style::Close|sf::Style::Titlebar);
	data->renderWindow.setFramerateLimit(FPS_LIMIT);
	data->stateManager.AddState(StateRef(new SplashState(this->data)));
}


void MainGame::Run()
{
	while (this->data->renderWindow.isOpen()) {
		this->data->stateManager.ProcessStateChanges();
			this->data
				->stateManager
				.GetActiveState()
				->HandleInput();
			this->data
				->stateManager
				.GetActiveState()
				->Update();
			this->data
				->stateManager
				.GetActiveState()
				->Draw();
	}
}


