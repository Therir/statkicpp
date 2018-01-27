#include "stdafx.h"
#include "silnik.h"
#include <SFML/Graphics.hpp>
#include <iostream>

silnik::silnik()
{
/*	window.create(sf::VideoMode(1500, 900), "statki");
	running = true;
	for (int i = 0; i < 10; i++) {
		P1.ustawPozycjeSprite(i, 800, 0 + 70 * i);
	}
	for (int i = 0; i < 10; i++) {
		O1.ustawPozycjeSprite(i, 800, 0 + 70 * i);
	}*/
	enStan = START;
}


silnik::~silnik()
{
}

bool silnik::ustawianie()
{
	
	std::cout << "jestem w ustawianiu";

	
	while (enStan == GRACZ1) {
		sf::Vector2i pozycjaMyszki = sf::Mouse::getPosition(window);


		//window.clear(sf::Color::Black);

		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.key.code == sf::Mouse::Left) {
				for (int i = 0; i <10; i++) {
					for (int j = 0; j<10; j++) {
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
				}
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
			col = (pozycjaMyszki.x - dx) / 70;
			row = (pozycjaMyszki.y - dy) / 70;
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
		
		window.display();
		window.clear();
		P1.drawPlansza(window, p1X, p1Y);
		for (int i = 0; i < 10; i++) {
			if (!(P1.zwrocStatek(i).czyUstawiony())) {
				window.draw(P1.zwrocSprite(i));
			}
			else {
				P1.ustawPozycjeSprite(i, -800, -600);
			}
		}
		if (P1.czyWszystkieUstawione()) {
			enStan = GRACZ2;
		}
	}
	while (enStan == GRACZ2) {
		sf::Vector2i pozycjaMyszki = sf::Mouse::getPosition(window);
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
			break;
		}//potrzebne do drag and drop
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.key.code == sf::Mouse::Left) {
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						if (O1.zwrocSprite(i).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
							ruch = true;
							n = i;
							dx = pozycjaMyszki.x - O1.zwrocSprite(i).getPosition().x;
							dy = pozycjaMyszki.y - O1.zwrocSprite(i).getPosition().y;
							/*if (O1.zwrocSpritePola(i, j).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
								dxPola = pozycjaMyszki.x - O1.zwrocSpritePola(i, j).getPosition().x;
								dyPola = pozycjaMyszki.y - O1.zwrocSpritePola(i, j).getPosition().y;
								/*if (reset.zwrocSprite().getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
								naReset = true;
								}
								else {
								naReset = false;
								}

							}*/
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
				}
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
		window.display();
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
			enStan = ROZGRYWKA;

		}
	}
	std::cout << "\n window display";
	if (enStan == ROZGRYWKA) {
		return true;
	}
	else
	{
		return false;
	}
}

bool silnik::rogrywka()
{
	enStan = GRACZ1;//zmiana z rozgrywki
	//sf::Vector2i pozycjaMyszki = sf::Mouse::getPosition(window);
	//window.clear();
	while (!(P1.czyKoniec()) || !(O1.czyKoniec())) {
		sf::Vector2i pozycjaMyszki = sf::Mouse::getPosition(window);
		window.pollEvent(event);
		P1.drawPlanszaUkryta(window, 10, 0);
		O1.drawPlanszaUkryta(window, 800, 0);
		std::cout << "\n enStat = "<<enStan;

		if (enStan == GRACZ1) {
			
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.key.code == sf::Mouse::Left) {
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 10; j++) {
							if (O1.zwrocSpritePola(i, j).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {//sprawdza czy myszka jest na odpowiedniej planszy
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
					if (!(O1.strzal(row, col))) {//jezeli pudlo to zmiana gracza
						enStan = GRACZ2;
						std::cout << "\nzmiana na gracz 2";

					}
				}
			}
		
		}


		if (enStan == GRACZ2) {
			//P1.drawPlanszaUkryta(window, 10, 0);
			//O1.drawPlanszaUkryta(window, 800, 0);
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.key.code == sf::Mouse::Left) {
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 10; j++) {
							if (P1.zwrocSpritePola(i, j).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {//sprawdza czy myszka jest na odpowiedniej planszy
								std::cout << "\npozycja myszki x: " << (pozycjaMyszki.x - 10) / 70 << "pozycja myszki y: " << pozycjaMyszki.y / 70;
								col = (pozycjaMyszki.x - 10) / 70;
								row = pozycjaMyszki.y / 70;

							}
						}
					}

				}
			}
			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.key.code == sf::Mouse::Left) {
					if (!(P1.strzal(row, col))) {//jezeli pudlo to zmiana gracza
						enStan = GRACZ1;
						std::cout << "\nzmiana na gracz 1";
					}
				}
			}


		}
		//std::cout << "\n window display rozgrywka";
		window.display();
		window.clear();
		}
	std::cout << "\nrozgrywka przed enStat = Koniec";
	enStan = KONIEC;
	return true;
}


void silnik::uruchom()
{
	while (this->enStan != KONIEC) {
		switch (this->enStan) {
		case MENU:
			this->menu();
			break;
		case START:
			std::cout << "jestem w start switch";

			this->inicjalizacja();
			this->ustawianie();
			break;
		case ROZGRYWKA:
			std::cout << "jestem w rozgrywce switch";
			this->rogrywka();
			break;
		default:
			break;
		}
	}
}

bool silnik::menu()
{
	return false;
}

bool silnik::inicjalizacja()
{


	window.create(sf::VideoMode(1500, 900), "statki");

	//K.drawPole(window);
	//P1.drawPlansza(window, 0, 0);
	//O1.drawPlansza(window, 600, 0);
	//window.display();
	for (int i = 0; i < 10; i++) {
		P1.ustawPozycjeSprite(i, 800, 0 + 70 * i);
	}
	for (int i = 0; i < 10; i++) {
		O1.ustawPozycjeSprite(i, 800, 0 + 70 * i);
	}
	//window.display();
	std::cout << "jestem w inicjalizacji";
	/*while (true)
	{
		//window.clear(sf::Color::Black);
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
			break;

		}
	}*/
	enStan = GRACZ1;
	return false;
}


