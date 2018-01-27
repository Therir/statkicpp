// statki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "plansza.h"
#include "pole.h"
#include <iostream>
#include "przycisk.h"
#include "silnik.h"
int main()
{
	/*pole K;
	plansza P1;
	plansza O1;
	Statek S1(1);
	przycisk reset; //TODO:dodac przycisk do resetowania ustawienia 
	float dx, dxPola=0.0f, dy, dyPola=0.0f;
	bool ruch = false;
	bool ustaw = false;
	bool doPoziomu = false;
	bool p1Ustawiony = false;
	bool o1Ustawiony = false;
	bool tarcza = false; //czasem za szybko przelaczy sie plansza co powoduje od razu klikniecie - potrzebny ten bool
	int row = 0, col = 0;
	int strzal = 0;
	bool kliknij = false;
	bool naReset = false;
	bool gracz1Strzela = true;
	int p1X = 10;
	int p1Y = 0;
	int o1X = 800;
	int o1Y = 0;

	sf::Event event;
	sf::RenderWindow window;

	window.create(sf::VideoMode(1500,900), "statki");
	//K.drawPole(window);
	//P1.drawPlansza(window, 0, 0);
	//O1.drawPlansza(window, 600, 0);

	//P1.drawPlansza(window, 0, 0);
	//P1.drawWybor(window, 10, 500);

	
	for (int i = 0; i < 10; i++) {
		P1.ustawPozycjeSprite(i, 800 , 0 + 70 * i);
	}
	for (int i = 0; i < 10; i++) {
		O1.ustawPozycjeSprite(i, 800, 0 + 70 * i);
	}
	int n = 0;
	while (true)
	{
	//	P1.ustawStatekLosowo();
	//	O1.ustawStatekLosowo();
		sf::Vector2i pozycjaMyszki = sf::Mouse::getPosition(window);
		
		
		//window.clear(sf::Color::Black);

		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
			break;
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.key.code == sf::Mouse::Left) {
				for(int i = 0; i <10; i++){
					for(int j=0; j<10; j++){
						if (P1.zwrocSprite(i).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
							ruch = true;
							n = i;
							dx = pozycjaMyszki.x - P1.zwrocSprite(i).getPosition().x;
							dy = pozycjaMyszki.y - P1.zwrocSprite(i).getPosition().y;
								/*
								if (reset.zwrocSprite().getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
									naReset = true;
								}
								else {
									naReset = false;
								}*/
	/*							
							
						}
					}
				}
			}
		}
		if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Right) {
			doPoziomu = true;
		}
		if (event.type == sf::Event::MouseButtonReleased) {
			if (event.key.code == sf::Mouse::Left) {
				if (ruch) {
					ruch = false;
					ustaw = true;
					/*if (naReset) {
						kliknij = true;
					}*/
	/*			}
			}
		}
		if (event.type == sf::Event::MouseButtonReleased) {
			if (event.key.code == sf::Mouse::Right) {
				if (doPoziomu) {
					bool poziom = P1.zwrocStatek(n).czyPoziomy();
					std::cout << "\nCzy poziomy przed: " << P1.zwrocStatek(n).czyPoziomy() << " n: " << n;
					P1.ustawOrientacjeStatku(n, !poziom);
					std::cout << " Czy poziomy po: " << P1.zwrocStatek(n).czyPoziomy() << " n: " << n;
					doPoziomu = false;
				}
			}
		}
		if (ruch) {
			P1.ustawPozycjeSprite(n, pozycjaMyszki.x - dx, pozycjaMyszki.y - dy);
			col = (pozycjaMyszki.x - dx)/70;
			row = (pozycjaMyszki.y - dy)/70;
		}
		if (row >= 0 && row <= 9 && col >= 0 && col <= 9) {
			if (ustaw && !(P1.zwrocPole(row, col).czyStatek())) {//zaprzeczenie bo domyslnie jest false;

			//	std::cout << "\nrow: " << row << "col: " << col;
			//	std::cout << "\nbstatek tam gdzie polozone PRZED: " << P1.zwrocPole(row, col).czyStatek();
				P1.ustawStatek(row, col, n);
			//	std::cout << "\nbstatek tam gdzie polozone PO: " << P1.zwrocPole(row, col).czyStatek();
			//	std::cout << "\nX PO: " << P1.zwrocPole(row, col).zwrocPozycje().first << "Y PO: " << P1.zwrocPole(row, col).zwrocPozycje().second;
				ustaw = false;
			}
		}
			window.clear();
		
		P1.drawPlansza(window, p1X, p1Y);
		for (int i = 0; i < 10; i++) {
			if (!(P1.zwrocStatek(i).czyUstawiony())) {
				window.draw(P1.zwrocSprite(i));
			}
			else {
				P1.ustawPozycjeSprite(i,-800,-600);
			}
		}
		if (P1.czyWszystkieUstawione()) {
			p1Ustawiony = true;
		}

		//------------------ Przejscie do ustawiania przeciwnika ------------------

		if (p1Ustawiony) {
			window.pollEvent(event);
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}//potrzebne do drag and drop
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.key.code == sf::Mouse::Left) {
					for (int i = 0; i <10; i++) {
						for (int j = 0; j<10; j++) {
							if (O1.zwrocSprite(i).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
								ruch = true;
								n = i;
								dx = pozycjaMyszki.x - O1.zwrocSprite(i).getPosition().x;
								dy = pozycjaMyszki.y - O1.zwrocSprite(i).getPosition().y;
								if (O1.zwrocSpritePola(i, j).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
									dxPola = pozycjaMyszki.x - O1.zwrocSpritePola(i, j).getPosition().x;
									dyPola = pozycjaMyszki.y - O1.zwrocSpritePola(i, j).getPosition().y;
									/*if (reset.zwrocSprite().getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
									naReset = true;
									}
									else {
									naReset = false;
									}*/

		/*						}
							}
						}
					}
				}
			}
			if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Right) {
				doPoziomu = true;
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.key.code == sf::Mouse::Left) {
					if (ruch) {
						ruch = false;
						ustaw = true;
						/*if (naReset) {
						kliknij = true;
						}*/
	/*				}
				}
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.key.code == sf::Mouse::Right) {
					if (doPoziomu) {
						bool poziom = O1.zwrocStatek(n).czyPoziomy();
						//std::cout << "\nCzy poziomy przed: " << O1.zwrocStatek(n).czyPoziomy() << " n: " << n;
						O1.ustawOrientacjeStatku(n, !poziom);
						//std::cout << " Czy poziomy po: " << O1.zwrocStatek(n).czyPoziomy() << " n: " << n;
						doPoziomu = false;
					}
				}
			}
			if (ruch) {
				O1.ustawPozycjeSprite(n, pozycjaMyszki.x - dx, pozycjaMyszki.y - dy);
				col = (pozycjaMyszki.x - dx) / 70;
				row = (pozycjaMyszki.y - dy) / 70;
			}
			if (row >= 0 && row <= 9 && col >= 0 && col <= 9) {
				if (ustaw && !(O1.zwrocPole(row, col).czyStatek())) {//zaprzeczenie bo domyslnie jest false;
					O1.ustawStatek(row, col, n);
					ustaw = false;
				}
			}
			window.clear();

			O1.drawPlansza(window, p1X, p1Y);
			for (int i = 0; i < 10; i++) {
				if (!(O1.zwrocStatek(i).czyUstawiony())) {
					window.draw(O1.zwrocSprite(i));
				}
				else {//wyrzuca poza okno sprite i nie rysuje go
					O1.ustawPozycjeSprite(i, -800, -600);
				}
			}
			if (O1.czyWszystkieUstawione()) {
				o1Ustawiony = true;

			}
			
		}
		/*---------------- koniec segmentu ustawiania -------------------*/


		/*---------------- segment rozgrywki -------------------*/
		//(pozycja myszki.x - 800) / 70
	/*	ustaw = false;
		tarcza = false;
		if (p1Ustawiony && o1Ustawiony) {
			//while (!(P1.czyKoniec()) || !(O1.czyKoniec())) {
			
				window.clear();
				if (gracz1Strzela) {
					P1.drawPlansza(window, p1X, p1Y);
					O1.drawPlanszaUkryta(window, o1X, o1Y);
					
					if (event.type == sf::Event::MouseButtonPressed) {
						if (event.key.code == sf::Mouse::Left) {
							for (int i = 0; i < 10; i++) {
								for (int j = 0; j < 10; j++) {
									if (O1.zwrocSpritePola(i, j).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
										std::cout << "\npozycja myszki x: " << (pozycjaMyszki.x - 800) / 70 << "pozycja myszki y: " << pozycjaMyszki.y / 70;
										col = (pozycjaMyszki.x - 800) / 70;
										row = pozycjaMyszki.y  / 70;
									
									}
								}
							}
							
						}
					}
					if (event.type == sf::Event::MouseButtonReleased) {
						if (event.key.code == sf::Mouse::Left) {
							
								ustaw = true;
								//tarcza = false;
							
						}
					}
	
				//	if (ustaw) {							
							if (O1.strzal(row, col)) {
								gracz1Strzela = true;
								strzal++;
								}
								else {
								//	gracz1Strzela = false;
									//tarcza = false;
									//strzal = 0;
								}					
				//	}
					//gracz1Strzela = false;
				}
				else {
					P1.drawPlanszaUkryta(window, o1X, o1Y);
					O1.drawPlansza(window, p1X, p1Y);
					//gracz1Strzela = true;
					/*if (strzal <= 0) {
						if (event.type == sf::Event::MouseButtonPressed) {
							if (event.key.code == sf::Mouse::Left) {
								for (int i = 0; i < 10; i++) {
									for (int j = 0; j < 10; j++) {
										if (O1.zwrocSpritePola(i, j).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
											std::cout << "\npozycja myszki x: " << (pozycjaMyszki.x - 800) / 70 << "pozycja myszki y: " << pozycjaMyszki.y / 70;
											col = (pozycjaMyszki.x - 800) / 70;
											row = pozycjaMyszki.y / 70;

										}
									}
								}

							}
						}
						if (event.type == sf::Event::MouseButtonReleased) {
							if (event.key.code == sf::Mouse::Left) {

								ustaw = true;


							}
						}

						if (ustaw) {
							if (P1.strzal(row, col)) {
								gracz1Strzela = false;
								strzal--
							}
							else {
								gracz1Strzela = true;

							}
						}
					}*/
/*				}
			//}
		}
		window.display();
		}
	//window.clear();
	
	*/
silnik gra;
gra.uruchom();
    return 0;
}

