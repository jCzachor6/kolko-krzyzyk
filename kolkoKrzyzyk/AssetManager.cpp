#include "AssetManager.hpp"

void AssetManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;
	if (tex.loadFromFile(fileName)) {
		this->textures[name] = tex;
	}
}

sf::Texture & AssetManager::GetTexture(std::string name)
{
	return this->textures.at(name);
}

void AssetManager::RemoveTexture(std::initializer_list<std::string> stringList)
{
	std::map<std::string, sf::Texture>::iterator it;
	for (std::string removed :stringList) {
		it = this->textures.find(removed);
		this->textures.erase(it);
	}
}

