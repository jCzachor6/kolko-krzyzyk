#include "Selector.hpp"



Selector::Selector(GameDataPtr data)
{
	this->data = data;
}


Selector::~Selector()
{
}

void Selector::addSelectable(sf::Vector2f pos, int returnValue, std::string notSelected, std::string selected)
{
	Selectable item;
	item.sprite = sf::Sprite(data->assetManager.GetTexture(notSelected));
	item.sprite.setPosition(pos);
	item.notSelected = notSelected;
	item.selected = selected;
	item.returnValue = returnValue;
	items.push_back(item);
}

void Selector::handleInput()
{
	for (int i = 0; i < items.size(); i++) {
		if (data->inputManager.IsSpriteClicked(items.at(i).sprite, sf::Mouse::Button::Left, data->renderWindow)) {
			for (int j = 0; j < items.size(); j++) {
				if(j!=i) 
					items.at(j).sprite.setTexture(this->data->assetManager.GetTexture(items.at(j).notSelected));
			}
			items.at(i).sprite.setTexture(this->data->assetManager.GetTexture(items.at(i).selected));
			returnValue = items.at(i).returnValue;
		}
	}
}

void Selector::draw()
{
	for (int i = 0; i < items.size(); i++) {
		data->renderWindow.draw(items.at(i).sprite);
	}
}

void Selector::setDefault()
{
	items.at(0).sprite.setTexture(this->data->assetManager.GetTexture(items.at(0).selected));
	returnValue = items.at(0).returnValue;
}

int Selector::getReturnValue()
{
	return returnValue;
}
