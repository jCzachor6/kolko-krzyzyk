#include "MenuState.hpp"
#include "DEFINITIONS.hpp"
#include "PlayState.hpp"


MenuState::MenuState(GameDataRef data)
{
	this->data = data;
	this->selectedSize = 10;
	gridLayout = new  GridLayout(0, 0, GAME_WIDTH, GAME_HEIGHT);
	gridLayout->setRows(12, 12);
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
	p10Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_10sel"));
	p15Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_15"));
	p20Sprite.setTexture(this->data->assetManager.GetTextrure("Menu_State_20"));

	twoPlayers = new Button(this->data,
		sf::Vector2i(gridLayout->getPosition(6, 5)),
		"Menu_State_Two", "Menu_State_Twosel");
	twoPlayers->setOnClick([&]() {
	data->stateManager.AddState(StateRef(new PlayState(this->data, selectedSize)));
	});
	
	onePlayer = new Button(this->data,
		sf::Vector2i(gridLayout->getPosition(6, 7)),
		"Menu_State_One", "Menu_State_Onesel");
	onePlayer->setOnClick([&]() {
		//data->stateManager.AddState(StateRef(new PlayBotState(this->data, selectedSize)));
	});

	exitGame = new Button(this->data,
		sf::Vector2i(gridLayout->getPosition(6, 9)),
		"Menu_State_Exit", "Menu_State_Exitsel");
	exitGame->setOnClick([&]() {
		data->renderWindow.close();
	});

	//todo add 'rozmiar' sprite
	p10Sprite.setPosition(gridLayout->getPosition(4, 3));
	p15Sprite.setPosition(gridLayout->getPosition(6, 3));
	p20Sprite.setPosition(gridLayout->getPosition(8, 3));
}

void MenuState::HandleInput()
{
	sf::Event event;

	while (data->renderWindow.pollEvent(event)) {
		if (sf::Event::Closed == event.type) {
			data->renderWindow.close();
		}

		twoPlayers->handleInput();
		onePlayer->handleInput();
		exitGame->handleInput();
		

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
	}
}

void MenuState::Update(float dt)
{
}

void MenuState::Draw(float dt)
{
	data->renderWindow.clear();
	data->renderWindow.draw(backgroundSprite);
	data->renderWindow.draw(p10Sprite);
	data->renderWindow.draw(p15Sprite);
	data->renderWindow.draw(p20Sprite);
	twoPlayers->draw();
	onePlayer->draw();
	exitGame->draw();
	data->renderWindow.display();
}

