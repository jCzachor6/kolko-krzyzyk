#include "PlayState.hpp"
#include <iostream>


PlayState::PlayState(GameDataRef data, int size)
{
	this->data = data;
	this->board_size = size;
	this->xTurn = true;
	this->isWin = false;
}

void PlayState::Init()
{
	data->assetManager.LoadTexture("Menu_State_Background", "Resources/PlayState/playScreen.png");
	data->assetManager.LoadTexture("tile_empty", "Resources/PlayState/empty.png");
	data->assetManager.LoadTexture("tile_selected", "Resources/PlayState/selected.png");
	data->assetManager.LoadTexture("tile_circle", "Resources/PlayState/circle.png");
	data->assetManager.LoadTexture("tile_cross", "Resources/PlayState/cross.png");
	data->assetManager.LoadTexture("O", "Resources/PlayState/O.png");
	data->assetManager.LoadTexture("X", "Resources/PlayState/X.png");
	data->assetManager.LoadTexture("arrow", "Resources/PlayState/arrow.png");

	backgroundSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_Background"));
	circleSprite.setTexture(this->data->assetManager.GetTextrure("O"));
	crossSprite.setTexture(this->data->assetManager.GetTextrure("X"));
	arrowSprite.setTexture(this->data->assetManager.GetTextrure("arrow"));

	board = new Board(this->data, this->board_size);

	circleSprite.setPosition(40, 120);
	crossSprite.setPosition(40 +circleSprite.getGlobalBounds().width, 120);
}

void PlayState::HandleInput()
{
	sf::Event event;
	while (data->renderWindow.pollEvent(event)) {
		if (sf::Event::Closed == event.type) {
			data->renderWindow.close();
		}
		board->handleInput(&xTurn);
	}
}

void PlayState::Update(float dt)
{
	if (xTurn) {
		arrowSprite.setPosition(40 + circleSprite.getGlobalBounds().width, 130 + circleSprite.getGlobalBounds().height);
	}else {
		arrowSprite.setPosition(40, 130 + circleSprite.getGlobalBounds().height);
	}

	if (isWin) {
		if(xTurn)
			std::cout << "O wygralo" << std::endl;
		else std::cout << "X wygralo" << std::endl;
		isWin = false;
	}
	else {
		board->update(&isWin);
	}
}

void PlayState::Draw(float dt)
{
	data->renderWindow.clear();
	data->renderWindow.draw(backgroundSprite);
	data->renderWindow.draw(circleSprite);
	data->renderWindow.draw(crossSprite);
	data->renderWindow.draw(arrowSprite);
	board->drawTiles();
	data->renderWindow.display();
}
