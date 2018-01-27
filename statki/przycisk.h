#pragma once
#include <SFML\Graphics.hpp>
#include "Sprites.h"

class przycisk
{
public:
	przycisk();
	~przycisk();
	void ustawPrzycisk(int pozX, int pozY,sf::Color color);
	sf::Sprite zwrocSprite();
	Sprites wszystkieSprites;

private:
	sf::IntRect prostokat;
	sf::Sprite sprite;

};

