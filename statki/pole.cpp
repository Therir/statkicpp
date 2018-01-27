#include "stdafx.h"
#include "pole.h"
#include "Statek.h"
#include "Sprites.h"
#include "iostream"
#include <utility>


pole::pole()
{
	trafienie = false;
	pudlo = false;
	xpoz = 0;
	ypoz = 0;
	sprite = wszystkieSprites.poleSprite;
	//this->mStatek = NULL; //pokazuje czy statek jest na polu - domyslnie nie
	bStatek = false;
	wielkoscStatku = 0;
}


pole::~pole()
{
}

bool pole::czyTrafiony()
{
	return trafienie;
}

bool pole::czyPudlo()
{
	return pudlo;
}

void pole::strzal()
{
	this->trafienie = true;
	if (this->czyStatek()) {
		this->pudlo = false;
		sprite = wszystkieSprites.trafionySprite;
	}
	else {
		this->pudlo = true;
		sprite = wszystkieSprites.pudloSprite;
	}
}

bool pole::czyStatek()
{
	return bStatek;
}

void pole::ustawPozycje(int x, int y)
{
	xpoz = x;
	ypoz = y;



}

std::pair<int, int> pole::zwrocPozycje()
{
	return std::pair<int, int>(xpoz, ypoz);
}

/*bool pole::zatopiony()
{
	if (mStatek != NULL) {
		return (mStatek->czyZatopiony());

	}
	else {
		return false;
	}
}*/

int pole::zwrocRozmiarStatku()
{
	return this->wielkoscStatku;
}

/*void pole::umiescStatek(Statek *nowy)
{
	if (mStatek == NULL) {
		mStatek = nowy;
		//mStatek->ustawSprite();
	}
	else {
		std::cout << "Na tym polu juz jest statek";
	}
}*/

void pole::umiescStatek(bool nStatek,int rozmiar)
{
	this->wielkoscStatku = rozmiar;
	this->bStatek = nStatek;
	sprite = wszystkieSprites.statek1Sprite;
}



void pole::usunStatek()
{
	this->mStatek = NULL;
	sprite = wszystkieSprites.poleSprite;
}

Statek * pole::zwrocStatek()
{
	return this->mStatek;
}

void pole::drawPole(sf::RenderWindow & w,int pozX, int pozY)
{
	
	sprite.setPosition(this->xpoz*70+pozX,this->ypoz*70+pozY);
	w.draw(sprite);
}
