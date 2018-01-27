#pragma once
#include <utility>
#include "Sprites.h"
#include <SFML\Graphics.hpp>

class Statek
{
public:
	Statek();
	Statek(int rozmiar);
	~Statek();

	bool czyZatopiony();//sprawdza czy statek jest zatopiony
	void ustawRozmiar(int rozmiarNowy);//ustawia rozmiar statku
/*	void ustawPozycje(int wiersz,int kolumna);//ustawia pozycje statku na planszy*/
	void ustawOrientacje(bool poziom);
	std::pair <int, int> zwrocPozycje(int i);
	int zwrocRozmiar();
	bool czyPoziomy();
	bool czyUstawiony();
	void trafiony();
	void drawStatek(sf::RenderWindow &w, int pozX, int pozY);
	void ustawSprite();
	void ustawPola(int rozmiar,int wiersz, int kolumna);
	void ustaw();
	void zwrocWszystkiePola(std::pair <int, int> p[4]);
	sf::Sprite sprite;
	Sprites wszystkieSprites;
private:
	bool narysowany;
	bool zatopiony;
	bool poziomy; //zmienna okreslajaca czy statek jest poziomy czy pionowy
	bool ustawiony;
	int rozmiar; //zmienna okreslajaca rozmiar statku
	int zycieStracone;//zmienna okreslajaca ile razy zostal statek trafiony
	std::pair <int, int> gora, dol; //dwie pary zmiennych zawierajacych wspolrzedne gornej i dolnej krawedzi statku
	std::pair <int, int> pola[4];

};

