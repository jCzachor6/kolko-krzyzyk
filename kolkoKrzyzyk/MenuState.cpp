#include "MenuState.hpp"
#include "DEFINITIONS.hpp"
#include "PlayState.hpp"


MenuState::MenuState(GameDataRef data)
{
	this->data = data;
	this->selectedSize = 10;
	sf::Vector2i pos((GAME_WIDTH / 2) - p10Sprite.getGlobalBounds().width - 15, 50);
}

void MenuState::Init()
{
	data->assetManager.LoadTexture("Menu_State_Background", "Resources/MenuState/menuScreen.png");
	data->assetManager.LoadTexture("Menu_State_Two", "Resources/MenuState/dwoch.png");
	data->assetManager.LoadTexture("Menu_State_One", "Resources/MenuState/jeden.png");
	data->assetManager.LoadTexture("Menu_State_Exit", "Resources/MenuState/wyjscie.png");
	data->assetManager.LoadTexture("Menu_State_Twosel", "Resources/MenuState/dwoch_sel.png");
	data->assetManager.LoadTexture("Menu_State_Onesel", "Resources/MenuState/jeden_sel.png");
	data->assetManager.LoadTexture("Menu_State_Exitsel", "Resources/MenuState/wyjscie_sel.png");
	data->assetManager.LoadTexture("Menu_State_10", "Resources/MenuState/10.png");
	data->assetManager.LoadTexture("Menu_State_15", "Resources/MenuState/15.png");
	data->assetManager.LoadTexture("Menu_State_20", "Resources/MenuState/20.png");
	data->assetManager.LoadTexture("Menu_State_10sel", "Resources/MenuState/10_sel.png");
	data->assetManager.LoadTexture("Menu_State_15sel", "Resources/MenuState/15_sel.png");
	data->assetManager.LoadTexture("Menu_State_20sel", "Resources/MenuState/20_sel.png");

	backgroundSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_Background"));
	twoSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_Two"));
	oneSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_One"));
	exitSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_Exit"));
	p10Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_10sel"));
	p15Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_15"));
	p20Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_20"));

	twoSprite.setPosition((GAME_WIDTH / 2) - twoSprite.getGlobalBounds().width/ 2, 350);
	oneSprite.setPosition((GAME_WIDTH / 2) - oneSprite.getGlobalBounds().width / 2, 470);
	exitSprite.setPosition((GAME_WIDTH / 2) - exitSprite.getGlobalBounds().width / 2, 590);
	p10Sprite.setPosition((GAME_WIDTH / 2) - p10Sprite.getGlobalBounds().width - 15, 185);
	p15Sprite.setPosition((GAME_WIDTH / 2), 185);
	p20Sprite.setPosition((GAME_WIDTH / 2) + p10Sprite.getGlobalBounds().width + 15, 185);
}

void MenuState::HandleInput()
{
	sf::Event event;

	while (data->renderWindow.pollEvent(event)) {
		if (sf::Event::Closed == event.type) {
			data->renderWindow.close();
		}

		if (data->inputManager.IsSpriteClicked(p10Sprite, sf::Mouse::Button::Left, data->renderWindow)) {
			p10Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_10sel"));
			p15Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_15"));
			p20Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_20"));
			selectedSize = 10;
		}
		if (data->inputManager.IsSpriteClicked(p15Sprite, sf::Mouse::Button::Left, data->renderWindow)) {
			p10Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_10"));
			p15Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_15sel"));
			p20Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_20"));
			selectedSize = 15;
		}
		if (data->inputManager.IsSpriteClicked(p20Sprite, sf::Mouse::Button::Left, data->renderWindow)) {
			p10Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_10"));
			p15Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_15"));
			p20Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_20sel"));
			selectedSize = 20;
		}

		if (data->inputManager.IsSpriteClicked(twoSprite, sf::Mouse::Button::Left, data->renderWindow)) {
			data->stateManager.AddState(StateRef(new PlayState(this->data, selectedSize)));
		}
		if (data->inputManager.IsSpriteClicked(oneSprite, sf::Mouse::Button::Left, data->renderWindow)) {
			//TODO
			//		data->stateManager.AddState(StateRef(new PlayBotState(this->data, selectedSize)));
		}
		if (data->inputManager.IsSpriteClicked(exitSprite, sf::Mouse::Button::Left, data->renderWindow)) {
			data->renderWindow.close();
		}


		if (data->inputManager.IsMouseOnSprite(twoSprite, data->renderWindow)) {
			twoSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_Twosel"));
		}else{
			twoSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_Two"));
		}

		if (data->inputManager.IsMouseOnSprite(oneSprite, data->renderWindow)) {
			oneSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_Onesel"));
		}else {
			oneSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_One"));
		}

		if (data->inputManager.IsMouseOnSprite(exitSprite, data->renderWindow)) {
			exitSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_Exitsel"));
		}else {
			exitSprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_Exit"));
		}
	}
}

void MenuState::Update(float dt)
{
}

void MenuState::Draw(float dt)
{
	data->renderWindow.clear();
	data->renderWindow.draw(backgroundSprite);
	data->renderWindow.draw(twoSprite);
	data->renderWindow.draw(oneSprite);
	data->renderWindow.draw(exitSprite);
	data->renderWindow.draw(p10Sprite);
	data->renderWindow.draw(p15Sprite);
	data->renderWindow.draw(p20Sprite);
	data->renderWindow.display();
}

