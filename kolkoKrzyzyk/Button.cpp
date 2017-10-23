#include "Button.hpp"

Button::Button(GameDataPtr data, sf::Vector2i position, std::string notSelected, std::string selected)
{
	this->data = data;
	this->sprite.setTexture(this->data->assetManager.GetTexture(notSelected));
	this->sprite.setPosition(position.x-this->sprite.getGlobalBounds().width/2, position.y);
	this->notSelected = notSelected;
	this->selected = selected;
	this->onClick = defaultOnClick;
}

void Button::draw()
{
	data->renderWindow.draw(sprite);
}

void Button::handleInput()
{
	if (data->inputManager.IsSpriteClicked(sprite, sf::Mouse::Button::Left, data->renderWindow)) {
		this->onClick();
	}

	if (data->inputManager.IsMouseOnSprite(sprite, data->renderWindow)) {
		sprite.setTexture(this->data->assetManager.GetTexture(selected));
	}else {
		sprite.setTexture(this->data->assetManager.GetTexture(notSelected));
	}
}

void Button::setOnClick(std::function<void()> onClick)
{
	this->onClick = onClick;
}

