#pragma once
#include "plansza.h"
#include <utility>
class komputer
{
public:
	komputer();
	~komputer();
	void ustawPlansze(plansza &nowaPlansza);
	std::pair <int, int> strzal();

	bool sprawdz(int x,int y);
	int losujX();
	int losujY();
	int losuj();


	void komputerLatwy();//losowo po planszy zawsze
	void komputerSredni();//losowo po planszy, jak trafi to losowo dookola
	void komputerTrudny();//losowo po planszy, jak trafi to niszczy
	void komputerSredniStrzalX(int x);
	void komputerSredniStrzalY();
	bool komputerStrzalRand();

private:

	plansza planszaKomputer;
	int strzalX, strzalY,wylosowaneX,wylosowaneY;
	int tablicaStrzalow[10][10];
};

