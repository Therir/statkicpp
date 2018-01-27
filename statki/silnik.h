#pragma once
#include <SFML/Graphics.hpp>
#include "plansza.h"
#include "statek.h"
enum stan { MENU, GRACZ1, GRACZ2, KONIEC, START,ROZGRYWKA };

class silnik
{
public:
	silnik();
	~silnik();
	sf::RenderWindow window;
	sf::Event event;
	bool running;
	void uruchom();
	bool menu();
	bool inicjalizacja();
	bool ustawianie();
	bool rogrywka(); 


	bool ruch = false;
	bool doPoziomu = false;
	bool ustaw = false;
	int n, dx, dy, col, row;
	int p1X = 10;
	int p1Y = 0;
	int o1X = 800;
	int o1Y = 0;
private://todo:moze przeniesc do klasy gracz
	plansza P1; //gracz 1
	plansza O1; //gracz 2
	stan enStan;

};

