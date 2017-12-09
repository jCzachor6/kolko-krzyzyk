#pragma once
#include <map>
#include <SFML/Graphics.hpp>

/**
 * @class	AssetManager
 *
 * @brief	Manager for assets.
 * 			Holds all the textures and fonts.
 *
 * @author	Jakub Czachor
 * @date	04.12.2017
 */

class AssetManager
{
public:

	/**
	 * @fn	void AssetManager::LoadTexture(std::string name, std::string fileName);
	 *
	 * @brief	Loads a texture
	 *
	 * @param	name		The texture name.
	 * @param	fileName	Path to the file.
	 */

	void LoadTexture(std::string name, std::string fileName);

	/**
	 * @fn	void AssetManager::LoadFont(std::string name, std::string fileName);
	 *
	 * @brief	Loads a font
	 *
	 * @param	name		The font name.
	 * @param	fileName	Path to the file.
	 */

	void LoadFont(std::string name, std::string fileName);

	/**
	 * @fn	sf::Texture AssetManager::&GetTexture(std::string name);
	 *
	 * @brief	Gets a texture based on it's name
	 *
	 * @param	name	The name.
	 *
	 * @return	The texture.
	 */

	sf::Texture &GetTexture(std::string name);

	/**
	 * @fn	sf::Font AssetManager::&GetFont(std::string name);
	 *
	 * @brief	Gets a font based on it's name
	 *
	 * @param	name	The name.
	 *
	 * @return	The font.
	 */

	sf::Font &GetFont(std::string name);

	/**
	 * @fn	void AssetManager::RemoveTexture(std::initializer_list<std::string> stringList);
	 *
	 * @brief	Removes the textures described in string List
	 *
	 * @param	stringList	List of strings.
	 */

	void RemoveTexture(std::initializer_list<std::string> stringList);

	/**
	 * @fn	void AssetManager::RemoveFont(std::initializer_list<std::string> fontList);
	 *
	 * @brief	Removes the fonts described in font List
	 *
	 * @param	fontList	List of fonts.
	 */

	void RemoveFont(std::initializer_list<std::string> fontList);

private:
	/** @brief	Loaded textures */
	std::map<std::string, sf::Texture> textures;
	/** @brief	Loaded fonts */
	std::map<std::string, sf::Font> fonts;
};

