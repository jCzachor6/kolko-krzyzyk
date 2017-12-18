#include "MainGame.hpp"
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include <Windows.h>

MainGame::MainGame(int width, int height, std::string title)
{
	data->renderWindow.create(sf::VideoMode(width, height), title, sf::Style::Titlebar);
	data->renderWindow.setFramerateLimit(FPS_LIMIT);
	data->renderWindow.setKeyRepeatEnabled(false);
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

GameDataPtr MainGame::getData()
{
	return this->data;
}


void MainGame::Run()
{
	while (this->data->renderWindow.isOpen()) {
			this->data
				->stateManager
				.ProcessStateChanges();
			this->data
				->stateManager
				.GetCurrentState()
				->HandleInput();
			this->data
				->stateManager
				.GetCurrentState()
				->Update();
			this->data
				->stateManager
				.GetCurrentState()
				->Draw();
	}
}


