#include "Spinner.hpp"


Spinner::Spinner(GameDataPtr data, sf::Vector2f position, std::string notSelected, std::string selected, std::string font, int min, int max)
{
	this->data = data;

	this->spriteTop.setTexture(this->data->assetManager.GetTexture(notSelected));
	this->spriteTop.setPosition(position.x - this->spriteTop.getGlobalBounds().width / 2, position.y);
	this->spriteTop.setOrigin(this->spriteTop.getGlobalBounds().width, this->spriteTop.getGlobalBounds().height);
	this->spriteTop.scale(-1.0f, -1.0f);
	
	this->spriteBot.setTexture(this->data->assetManager.GetTexture(notSelected));
	this->spriteBot.setPosition(position.x - this->spriteBot.getGlobalBounds().width / 2, position.y + 1.5 * this->spriteTop.getGlobalBounds().height);
	this->notSelected = notSelected;
	this->selected = selected;

	this->minValue = min;
	this->maxValue = max;
	this->value = (min + max) / 2;

	this->textValue.setFont(this->data->assetManager.GetFont(font));
	textValue.setString(std::to_string(value));
	textValue.setCharacterSize(45);
	textValue.setFillColor(sf::Color::White);
	textValue.setOrigin(textValue.getGlobalBounds().width / 2, textValue.getGlobalBounds().height);
	textValue.setPosition(position.x - 5, position.y + spriteTop.getGlobalBounds().height + textValue.getGlobalBounds().height/2 -5);
}

void Spinner::draw()
{
	data->renderWindow.draw(spriteTop);
	data->renderWindow.draw(spriteBot);
	data->renderWindow.draw(textValue);
}

void Spinner::handleInput(sf::Event *ev)
{
	if (data->inputManager.IsSpritePressed(spriteBot, sf::Mouse::Button::Left, data->renderWindow, *ev)) {
		if (value != minValue) {
			value--;
			textValue.setString(std::to_string(value));
		}
	}
	if (data->inputManager.IsSpritePressed(spriteTop, sf::Mouse::Button::Left, data->renderWindow, *ev)) {
		if (value != maxValue) {
			value++;
			textValue.setString(std::to_string(value));
		}
	}

	if (data->inputManager.IsMouseOnSprite(spriteBot, data->renderWindow) && value > minValue) {
		spriteBot.setTexture(this->data->assetManager.GetTexture(selected));
		if (ev->type == sf::Event::MouseWheelMoved && ev->mouseWheel.delta <0)
		{
			value += ev->mouseWheel.delta;
			if (this->value < this->minValue) value = minValue;
			textValue.setString(std::to_string(value));
		}
	}
	else {
		spriteBot.setTexture(this->data->assetManager.GetTexture(notSelected));
	}
	if (data->inputManager.IsMouseOnSprite(spriteTop, data->renderWindow) && value < maxValue) {
		spriteTop.setTexture(this->data->assetManager.GetTexture(selected));
		if (ev->type == sf::Event::MouseWheelMoved && ev->mouseWheel.delta >0)
		{
			value += ev->mouseWheel.delta;
			if (this->value > this->maxValue) value = maxValue;
			textValue.setString(std::to_string(value));
		}
	}
	else {
		spriteTop.setTexture(this->data->assetManager.GetTexture(notSelected));
	}
}

int Spinner::getValue()
{
	return this->value;
}
