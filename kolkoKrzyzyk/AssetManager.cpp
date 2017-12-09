#include "AssetManager.hpp"

void AssetManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;
	if (tex.loadFromFile(fileName)) {
		this->textures[name] = tex;
	}else throw std::invalid_argument("missing texture file!");
}

void AssetManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;
	if (font.loadFromFile(fileName)) {
		this->fonts[name] = font;
	}else throw std::invalid_argument("missing font file!");
}

sf::Texture & AssetManager::GetTexture(std::string name)
{
	return this->textures.at(name);
}

sf::Font & AssetManager::GetFont(std::string name)
{
	return this->fonts.at(name);
}

void AssetManager::RemoveTexture(std::initializer_list<std::string> stringList)
{
	std::map<std::string, sf::Texture>::iterator it;
	for (std::string removed :stringList) {
		it = this->textures.find(removed);
		this->textures.erase(it);
	}
}

void AssetManager::RemoveFont(std::initializer_list<std::string> fontList)
{
	std::map<std::string, sf::Font>::iterator it;
	for (std::string removed : fontList) {
		it = this->fonts.find(removed);
		this->fonts.erase(it);
	}
}

