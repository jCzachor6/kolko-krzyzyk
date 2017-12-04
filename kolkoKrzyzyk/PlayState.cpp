#include "PlayState.hpp"
#include "DEFINITIONS.hpp"
#include "MenuState.hpp"

PlayState::PlayState(GameDataPtr data, int size)
{
	this->data = data;
	this->boardSize = size;
	this->xTurn = true;
	this->isWin = false;
	this->lockInput = false;
	gridLayout = new GridLayout(0, 0, GAME_WIDTH, GAME_HEIGHT);
	gridLayout->setRows(12, 36);
}

void PlayState::Init()
{
	data->assetManager.LoadTexture("Play_State_Background", "Resources/PlayState/playScreen.png");
	data->assetManager.LoadTexture("tile_empty", "Resources/PlayState/empty.png");
	data->assetManager.LoadTexture("tile_selected", "Resources/PlayState/selected.png");
	data->assetManager.LoadTexture("tile_circle", "Resources/PlayState/circle.png");
	data->assetManager.LoadTexture("tile_cross", "Resources/PlayState/cross.png");
	data->assetManager.LoadTexture("O", "Resources/PlayState/O.png");
	data->assetManager.LoadTexture("X", "Resources/PlayState/X.png");
	data->assetManager.LoadTexture("arrow", "Resources/PlayState/arrow.png");
	data->assetManager.LoadTexture("crown", "Resources/PlayState/crown.png");
	data->assetManager.LoadTexture("menu", "Resources/PlayState/menu.png");
	data->assetManager.LoadTexture("menusel", "Resources/PlayState/menusel.png");

	backgroundSprite.setTexture(this->data->assetManager.GetTexture("Play_State_Background"));
	sf::Vector2f newScale(GAME_WIDTH / backgroundSprite.getGlobalBounds().width, GAME_HEIGHT / backgroundSprite.getLocalBounds().height);
	backgroundSprite.setScale(newScale);

	circleSprite.setTexture(this->data->assetManager.GetTexture("O"));
	crossSprite.setTexture(this->data->assetManager.GetTexture("X"));
	arrowSprite.setTexture(this->data->assetManager.GetTexture("arrow"));

	board = new Board(this->data, this->boardSize);
	menuButton = new Button(
		this->data,
		sf::Vector2i(gridLayout->getPosition(33, 10)),
		"menu", "menusel");
	menuButton->setOnClick([&]() {
		data->stateManager.AddState(StatePtr(new MenuState(this->data)));
	});

	circleSprite.setPosition(gridLayout->getPosition(1, 2));
	crossSprite.setPosition(gridLayout->getPosition(4, 2));
}

void PlayState::HandleInput()
{
	sf::Event event;
	while (data->renderWindow.pollEvent(event)) {
		if (sf::Event::Closed == event.type) {
			data->renderWindow.close();
		}
			menuButton->handleInput();
			if (!lockInput) board->handleInput(&xTurn, &event);
	}
}

void PlayState::Update()
{
	switch (isWin) {
	case 'x':
		crownSprite.setTexture(this->data->assetManager.GetTexture("crown"));
		crownSprite.setPosition(gridLayout->getPosition(4, 1));
		arrowSprite.setPosition(gridLayout->getPosition(4, 3));
		lockInput = true;
		break;
	case 'o':
		crownSprite.setTexture(this->data->assetManager.GetTexture("crown"));
		crownSprite.setPosition(gridLayout->getPosition(1, 1));
		arrowSprite.setPosition(gridLayout->getPosition(1, 3));
		lockInput = true;
		break;
	default: 
		board->update(&isWin);
		if (xTurn) {
			arrowSprite.setPosition(gridLayout->getPosition(4, 3));
		}else {
			arrowSprite.setPosition(gridLayout->getPosition(1, 3));
		}
		break;
	}
}

void PlayState::Draw()
{
	data->renderWindow.clear();
	data->renderWindow.draw(backgroundSprite);
	data->renderWindow.draw(circleSprite);
	data->renderWindow.draw(crossSprite);
	data->renderWindow.draw(arrowSprite);
	data->renderWindow.draw(crownSprite);
	board->drawTiles();
	menuButton->draw();
	data->renderWindow.display();
}

void PlayState::Remove()
{
	delete gridLayout;
	if (board != NULL) {
		delete board;
	}
	if (menuButton != NULL) {
		delete menuButton;
	}
	data->assetManager.RemoveTexture({
		"Play_State_Background", 
		"tile_empty" , 
		"tile_selected",
		"tile_circle", 
		"tile_cross" , 
		"O",
		"X", 
		"arrow" , 
		"crown",
		"menu", 
		"menusel"
	});
}
