#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameStateManager.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"



struct GameData {
	GameStateManager stateManager;
	sf::RenderWindow renderWindow;
	AssetManager assetManager;
	InputManager inputManager;
};

typedef std::shared_ptr<GameData> GameDataRef;
class MainGame
{
public:
	MainGame(int width, int height, std::string title);
	void Run();
private:
	GameDataRef data = std::make_shared<GameData>();
};
