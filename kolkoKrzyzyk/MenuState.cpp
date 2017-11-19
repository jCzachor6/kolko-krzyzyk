#include "MenuState.hpp"
#include "DEFINITIONS.hpp"
#include "PlayState.hpp"
#include "PlayBotState.hpp"
#include <iostream>

MenuState::MenuState(GameDataPtr data)
{
	this->data = data;
	gridLayout = new  GridLayout(0, 0, GAME_WIDTH, GAME_HEIGHT);
	gridLayout->setRows(12, 12);
	boardSize = new Selector(this->data);
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

	backgroundSprite.setTexture(this->data->assetManager.GetTexture("Menu_State_Background"));
	sf::Vector2f newScale(GAME_WIDTH / backgroundSprite.getGlobalBounds().width, GAME_HEIGHT / backgroundSprite.getLocalBounds().height);
	backgroundSprite.setScale(newScale);

	twoPlayers = new Button(this->data,
		sf::Vector2i(gridLayout->getPosition(6, 5)),
		"Menu_State_Two", "Menu_State_Twosel");
	twoPlayers->setOnClick([&]() {
		data->stateManager.AddState(StatePtr(new PlayState(this->data, boardSize->getReturnValue())));
	});
	
	onePlayer = new Button(this->data,
		sf::Vector2i(gridLayout->getPosition(6, 7)),
		"Menu_State_One", "Menu_State_Onesel");
	onePlayer->setOnClick([&]() {
		data->stateManager.AddState(StatePtr(new PlayBotState(this->data, boardSize->getReturnValue(), 100)));
	});

	exitGame = new Button(this->data,
		sf::Vector2i(gridLayout->getPosition(6, 9)),
		"Menu_State_Exit", "Menu_State_Exitsel");
	exitGame->setOnClick([&]() {
		data->renderWindow.close();
	});
	
	boardSize->addSelectable(gridLayout->getPosition(4, 3), 10, "Menu_State_10", "Menu_State_10sel");
	boardSize->addSelectable(gridLayout->getPosition(6, 3), 15, "Menu_State_15", "Menu_State_15sel");
	boardSize->addSelectable(gridLayout->getPosition(8, 3), 20, "Menu_State_20", "Menu_State_20sel");
	boardSize->setDefault();
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
		boardSize->handleInput();
	}
}

void MenuState::Update()
{
}

void MenuState::Draw()
{
	data->renderWindow.clear();
	data->renderWindow.draw(backgroundSprite);
	boardSize->draw();
	twoPlayers->draw();
	onePlayer->draw();
	exitGame->draw();
	data->renderWindow.display();
}

void MenuState::Remove()
{
	delete gridLayout;
	delete boardSize;
	if (twoPlayers != NULL) {
		delete twoPlayers;
	}
	if (onePlayer != NULL) {
		delete onePlayer;
	}
	if (exitGame != NULL) {
		delete exitGame;
	}
	data->assetManager.RemoveTexture({ 
		"Menu_State_Background", 
		"Menu_State_Two" , 
		"Menu_State_One", 
		"Menu_State_Exit", 
		"Menu_State_Twosel" , 
		"Menu_State_Onesel", 
		"Menu_State_Exitsel",
		"Menu_State_10" , 
		"Menu_State_15", 
		"Menu_State_20", 
		"Menu_State_10sel" , 
		"Menu_State_15sel", 
		"Menu_State_20sel"
	});
}

