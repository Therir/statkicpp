#pragma once
#include "Statek.h"
#include "Sprites.h"
#include <utility>
class pole
{
public:
	pole();
	~pole();
	bool czyTrafiony();
	bool czyPudlo();
	void strzal();
	bool czyStatek();
	void ustawPozycje(int x, int y);
	std::pair <int, int> zwrocPozycje(); 
	//bool zatopiony();
	int zwrocRozmiarStatku();
	//void umiescStatek(Statek * nowy);
	void umiescStatek(bool nStatek, int rozmiar);
	void usunStatek();
	Statek * zwrocStatek();
	Sprites wszystkieSprites;
	sf::Sprite sprite;
	void drawPole(sf::RenderWindow &w, int pozX, int pozY);
	bool bStatek;
private:
	bool trafienie;
	bool pudlo;
	int xpoz, ypoz;
	Statek * mStatek;
	int wielkoscStatku;
	
};

