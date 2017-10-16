#include "MainGame.hpp"
#include "SplashState.hpp"

MainGame::MainGame(int width, int height, std::string title)
{
	data->renderWindow.create(sf::VideoMode(width, height), title, sf::Style::Close|sf::Style::Titlebar);
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
		newTime = this->clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;
		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}
		currentTime = newTime;
		accumulator += frameTime;
		while (accumulator >= dt) {
			this->data
				->stateManager
				.GetActiveState()
				->HandleInput();
			this->data
				->stateManager
				.GetActiveState()
				->Update(dt);

			accumulator -= dt;
		}
		interpolation = accumulator / dt;
		this->data->stateManager.GetActiveState()->Draw(interpolation);
	}

}


