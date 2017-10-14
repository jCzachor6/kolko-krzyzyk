#include "AssetManager.hpp"

void AssetManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;
	if (tex.loadFromFile(fileName)) {
		this->textures[name] = tex;
	}
}

sf::Texture & AssetManager::GetTextrure(std::string name)
{
	return this->textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;
	if (font.loadFromFile(fileName)) {
		this->fonts[name] = font;
	}
}

sf::Font & AssetManager::GetFont(std::string name)
{
	return this->fonts.at(name);
}
