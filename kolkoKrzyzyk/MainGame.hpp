#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "GameStateManager.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

/**
 * @struct	GameData
 *
 * @brief	A game data. 
 * 			Contains GameStateManager, RenderWindow, AssetManager, InputManager
 *
 * @author	Jakub Czachor
 * @date	04.12.2017
 */

struct GameData {
	/** @brief	Manager for states */
	GameStateManager stateManager;
	/** @brief	The game window */
	sf::RenderWindow renderWindow;
	/** @brief	Manager for assets(textures and fonts) */
	AssetManager assetManager;
	/** @brief	Manager for input */
	InputManager inputManager;
};

/**
 * @typedef	std::shared_ptr<GameData> GameDataPtr
 *
 * @brief	Defines an alias representing the game data pointer
 */

typedef std::shared_ptr<GameData> GameDataPtr;

/**
 * @class	MainGame
 *
 * @brief	A main game loop.
 *
 * @author	Jakub
 * @date	04.12.2017
 */

class MainGame
{
public:

	/**
	 * @fn	MainGame::MainGame(int width, int height, std::string title);
	 *
	 * @brief	Constructor
	 *
	 * @param	width 	The window width.
	 * @param	height	The window height.
	 * @param	title 	The window title.
	 */

	MainGame(int width, int height, std::string title);

	/**
	 * @fn	GameDataPtr MainGame::getData();
	 *
	 * @brief	Gets the game data
	 *
	 * @return	The game data.
	 */

	GameDataPtr getData();

	/**
	 * @fn	void MainGame::Run();
	 *
	 * @brief	Runs the game loop
	 */

	void Run();
private:
	/** @brief	The game data */
	GameDataPtr data = std::make_shared<GameData>();
};

