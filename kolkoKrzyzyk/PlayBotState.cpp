#include "PlayBotState.hpp"
#include "DEFINITIONS.hpp"
#include "MenuState.hpp"

PlayBotState::PlayBotState(GameDataPtr data, int sizeX, int sizeY)
{
	this->data = data;
	this->data->renderWindow.setSize(sf::Vector2u(160 + sizeX * 32, sizeY * 32));
	sf::View mGUIView = sf::View(sf::FloatRect(0.f, 0.f, 160 + sizeX * 32, sizeY * 32));
	this->data->renderWindow.setView(mGUIView);
	this->boardSizeY = sizeY;
	this->boardSizeX = sizeX;
	this->xTurn = true;
	this->isWin = 'e';
	this->lockInput = false;
}

void PlayBotState::Init()
{
	data->assetManager.LoadTexture("Play_State_Background", "Resources/PlayState/playScreen.png");
	data->assetManager.LoadTexture("tile_empty", "Resources/PlayState/empty.png");
	data->assetManager.LoadTexture("tile_selected", "Resources/PlayState/selected.png");
	data->assetManager.LoadTexture("tile_circle", "Resources/PlayState/circle.png");
	data->assetManager.LoadTexture("tile_cross", "Resources/PlayState/cross.png");
	data->assetManager.LoadTexture("ai", "Resources/PlayState/AI.png");
	data->assetManager.LoadTexture("O", "Resources/PlayState/O.png");
	data->assetManager.LoadTexture("X", "Resources/PlayState/X.png");
	data->assetManager.LoadTexture("arrow", "Resources/PlayState/arrow.png");
	data->assetManager.LoadTexture("crown", "Resources/PlayState/crown.png");
	data->assetManager.LoadTexture("menu", "Resources/PlayState/menu.png");
	data->assetManager.LoadTexture("menusel", "Resources/PlayState/menusel.png");

	aiSprite.setTexture(this->data->assetManager.GetTexture("ai"));
	circleSprite.setTexture(this->data->assetManager.GetTexture("O"));
	crossSprite.setTexture(this->data->assetManager.GetTexture("X"));
	arrowSprite.setTexture(this->data->assetManager.GetTexture("arrow"));

	board = new Board(this->data, this->boardSizeX, this->boardSizeY);
	bot = new AI();

	menuButton = new Button(
		this->data,
		sf::Vector2i(64, boardSizeY * 32 - 64),
		"menu", "menusel");
	menuButton->setOnClick([&]() {
		data->stateManager.AddState(StatePtr(new MenuState(this->data)));
	});

	aiSprite.setPosition(0, 64);
	circleSprite.setPosition(0, 64);
	crossSprite.setPosition(64, 64);
}

void PlayBotState::HandleInput()
{
	sf::Event event;
	while (data->renderWindow.pollEvent(event)) {
		if (sf::Event::Closed == event.type) {
			data->renderWindow.close();
		}
		menuButton->handleInput();
		if(!lockInput && xTurn) board->handleInput(&xTurn, &event);
	}
}

void PlayBotState::Update()
{	
	switch (isWin) {
	case 'x':
		crownSprite.setTexture(this->data->assetManager.GetTexture("crown"));
		crownSprite.setPosition(64, 0);
		arrowSprite.setPosition(64, 128);
		lockInput = true;
		break;
	case 'o':
		crownSprite.setTexture(this->data->assetManager.GetTexture("crown"));
		crownSprite.setPosition(0, 0);
		arrowSprite.setPosition(0, 128);
		lockInput = true;
		break;
	default:
		if (xTurn) {
			arrowSprite.setPosition(64, 128);
		}else {
			arrowSprite.setPosition(0, 128);
			bot->analyze(board->getBoardTileStates());
			board->setPoint(bot->getHighestPoint(), 'o');
			xTurn = true;
			board->update(&isWin);
		}
		break;
	}
}

void PlayBotState::Draw()
{
	data->renderWindow.clear();
	data->renderWindow.draw(circleSprite);
	data->renderWindow.draw(aiSprite);
	data->renderWindow.draw(crossSprite);
	data->renderWindow.draw(arrowSprite);
	data->renderWindow.draw(crownSprite);
	board->drawTiles();
	menuButton->draw();
	data->renderWindow.display();
}

void PlayBotState::Remove()
{
	if (board != NULL) {
		delete board;
	}
	if (menuButton != NULL) {
		delete menuButton;
	}
	if (bot != NULL) {
		delete bot;
	}
	data->assetManager.RemoveTexture({
		"Play_State_Background",
		"tile_empty" ,
		"tile_selected",
		"tile_circle",
		"tile_cross" ,
		"ai",
		"O",
		"X",
		"arrow" ,
		"crown",
		"menu",
		"menusel"
	});
}
