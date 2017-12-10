#include "MenuState.hpp"
#include "DEFINITIONS.hpp"
#include "PlayState.hpp"
#include "PlayBotState.hpp"
#include <iostream>


MenuState::MenuState(GameDataPtr data)
{
	this->data = data;
	this->data->renderWindow.setSize(sf::Vector2u(GAME_WIDTH, GAME_HEIGHT));
	sf::View mGUIView = sf::View(sf::FloatRect(0.f, 0.f, GAME_WIDTH, GAME_HEIGHT));
	this->data->renderWindow.setView(mGUIView);
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
	data->assetManager.LoadTexture("Menu_State_spinner", "Resources/MenuState/spinner.png");
	data->assetManager.LoadTexture("Menu_State_spinnersel", "Resources/MenuState/spinner_sel.png");
	data->assetManager.LoadFont("font", "Resources/Fonts/DroidSansMono-Regular.ttf");

	backgroundSprite.setTexture(this->data->assetManager.GetTexture("Menu_State_Background"));
	sf::Vector2f newScale(GAME_WIDTH / backgroundSprite.getGlobalBounds().width, GAME_HEIGHT / backgroundSprite.getLocalBounds().height);
	backgroundSprite.setScale(newScale);

	
	sf::VideoMode mode = sf::VideoMode::getDesktopMode();
	int maxHeight = (mode.height - 64) / 32;
	int maxWidth =  (mode.width - 160 - 64) / 32;

	boardSizeY = new Spinner(this->data, gridLayout->getPosition(5, 3), "Menu_State_spinner", "Menu_State_spinnersel", "font", 10, maxHeight);
	boardSizeX = new Spinner(this->data, gridLayout->getPosition(7, 3), "Menu_State_spinner", "Menu_State_spinnersel", "font", 10, maxWidth);

	twoPlayers = new Button(this->data,
		sf::Vector2i(gridLayout->getPosition(6, 5)),
		"Menu_State_Two", "Menu_State_Twosel");
	twoPlayers->setOnClick([&]() {
		data->stateManager.AddState(StatePtr(new PlayState(this->data, boardSizeX->getValue(), boardSizeY->getValue())));
	});
	
	onePlayer = new Button(this->data,
		sf::Vector2i(gridLayout->getPosition(6, 7)),
		"Menu_State_One", "Menu_State_Onesel");
	onePlayer->setOnClick([&]() {
		data->stateManager.AddState(StatePtr(new PlayBotState(this->data, boardSizeX->getValue(), boardSizeY->getValue())));
	});

	exitGame = new Button(this->data,
		sf::Vector2i(gridLayout->getPosition(6, 9)),
		"Menu_State_Exit", "Menu_State_Exitsel");
	exitGame->setOnClick([&]() {
		data->renderWindow.close();
	});


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
		boardSizeY->handleInput(&event);
		boardSizeX->handleInput(&event);
	}
}

void MenuState::Update()
{
}

void MenuState::Draw()
{
	data->renderWindow.clear();
	data->renderWindow.draw(backgroundSprite);
	boardSizeY->draw();
	boardSizeX->draw();
	twoPlayers->draw();
	onePlayer->draw();
	exitGame->draw();
	data->renderWindow.display();
}

void MenuState::Remove()
{
	delete gridLayout;
	if (boardSizeX != NULL) {
		delete boardSizeX;
	}
	if (boardSizeY != NULL) {
		delete boardSizeY;
	}
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
		"Menu_State_spinner",
		"Menu_State_spinnersel"
	});
	data->assetManager.RemoveFont({
		"font"
	});
}

