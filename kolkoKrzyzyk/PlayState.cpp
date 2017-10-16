#include "PlayState.hpp"



PlayState::PlayState(GameDataRef data, int size)
{
	this->data = data;
	this->board_size = size;
}

void PlayState::Init()
{
	data->assetManager.LoadTexture("Menu_State_Background", "Resources/MenuState/menuScreen.png");
	data->assetManager.LoadTexture("tile_empty", "Resources/PlayState/empty.png");
	data->assetManager.LoadTexture("tile_selected", "Resources/PlayState/selected.png");
	data->assetManager.LoadTexture("tile_circle", "Resources/PlayState/circle.png");
	data->assetManager.LoadTexture("tile_cross", "Resources/PlayState/cross.png");
	backgroundSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_Background"));
}

void PlayState::HandleInput()
{
	sf::Event event;
	while (data->renderWindow.pollEvent(event)) {
		if (sf::Event::Closed == event.type) {
			data->renderWindow.close();
		}
	}
}

void PlayState::Update(float dt)
{
}

void PlayState::Draw(float dt)
{
	data->renderWindow.clear();
	data->renderWindow.draw(backgroundSprite);
	data->renderWindow.display();
}
