#pragma once
#include <map>
#include <SFML/Graphics.hpp>

class AssetManager
{
public:
	AssetManager() {};
	~AssetManager() {};
	void LoadTexture(std::string name, std::string fileName);
	void LoadFont(std::string name, std::string fileName);

	sf::Texture &GetTexture(std::string name);
	sf::Font &GetFont(std::string name);

	void RemoveTexture(std::initializer_list<std::string> stringList);
	void RemoveFont(std::initializer_list<std::string> fontList);

private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
};

