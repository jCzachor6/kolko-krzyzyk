#include "MainGame.hpp"
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"

MainGame::MainGame(int width, int height, std::string title)
{
	data->renderWindow.create(sf::VideoMode(width, height), title, sf::Style::Close|sf::Style::Titlebar);
	data->renderWindow.setFramerateLimit(FPS_LIMIT);
	data->stateManager.AddState(StateRef(new SplashState(this->data)));
}

MainGame::~MainGame()
{
}

void MainGame::Run()
{
	float newTime;
	float frameTime;
	float interpolation;
	float currentTime = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

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


