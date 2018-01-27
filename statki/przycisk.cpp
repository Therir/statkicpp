#include "stdafx.h"
#include "przycisk.h"
#include "Sprites.h"


przycisk::przycisk()
{
}


przycisk::~przycisk()
{
}

void przycisk::ustawPrzycisk(int pozX, int pozY,sf::Color color)
{
	this->sprite.setColor(color);
	this->sprite = wszystkieSprites.przyciskSprite;
	this->sprite.setPosition(pozX, pozY);



}

sf::Sprite przycisk::zwrocSprite()
{
	return this->sprite;
}
