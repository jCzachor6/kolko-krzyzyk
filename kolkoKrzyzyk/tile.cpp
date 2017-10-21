#include "tile.hpp"



tile::tile(GameDataRef data, int x, int y)
{
	this->data = data;
	setState('e');
	this->sprite.setPosition(x, y);

}

void tile::drawTile()
{
	data->renderWindow.draw(sprite);
}

void tile::setState(char state)
{
	switch (state){
	case 'o':
		this->state = 'o';
		sprite.setTexture(data->assetManager.GetTexture("tile_circle"));
		break;
	case 'x':
		this->state = 'x';
		sprite.setTexture(data->assetManager.GetTexture("tile_cross"));
		break;
	default:
		this->state = 'e';
		sprite.setTexture(data->assetManager.GetTexture("tile_empty"));
		break;
	}
}

void tile::handleInput(bool *xTurn, bool *isChecked)
{
	if (isEmpty()) {
		if (data->inputManager.IsMouseOnSprite(this->sprite, data->renderWindow)) {
			this->sprite.setTexture(this->data->assetManager.GetTexture("tile_selected"));
			if ((data->inputManager.IsSpriteClicked(this->sprite, sf::Mouse::Button::Left, data->renderWindow))) {
				if (*xTurn) {
					setState('x');
					*xTurn = false;
					*isChecked = false;
				}else {
					setState('o');
					*xTurn = true;
					*isChecked = false;
				}
			}
		}
		else {
			sprite.setTexture(data->assetManager.GetTexture("tile_empty"));
		}
	}
}

bool tile::isEmpty()
{
	return (this->state == 'e');
}

char tile::getState()
{
	return this->state;
}


