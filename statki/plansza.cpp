#include "stdafx.h"
#include "plansza.h"
#include <iostream>
#include "Sprites.h"


plansza::plansza()
{
	S[0].ustawRozmiar(4);
	S[1].ustawRozmiar(3);
	S[2].ustawRozmiar(3);
	S[3].ustawRozmiar(2);
	S[4].ustawRozmiar(2);
	S[5].ustawRozmiar(2);
	for (int i = 6; i <= 10; i++) {
		S[i].ustawRozmiar(1);
	}
	planszaUstawiona = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->P[i][j].ustawPozycje(j, i);//TODO: czemu j,i a nie i,j?
		}
	}
}


plansza::~plansza()
{
}

bool plansza::ustawStatek(int wiersz, int kolumna, int num)
{
	if (!(this->S[num].czyUstawiony())) {
		if (sprawdzOkolice(wiersz, kolumna, num)) {
			if (S[num].czyPoziomy()) {
				for (int i = 0; i < S[num].zwrocRozmiar(); i++) {//petla do ustawiania statku, zaznacza ze statek znajduje sie na odpowiednich polach
					//S[num].ustawPozycje(wiersz, kolumna);
					P[wiersz][kolumna + i].umiescStatek(true, S[num].zwrocRozmiar());
					S[num].ustawPola(i, wiersz, kolumna);
					S[num].ustaw();
				}
				return true;
			}
			else {
				for (int i = 0; i < S[num].zwrocRozmiar(); i++) {
				//	S[num].ustawPozycje(wiersz, kolumna);
					P[wiersz + i][kolumna].umiescStatek(true,S[num].zwrocRozmiar());
					S[num].ustawPola(i, wiersz, kolumna);
					S[num].ustaw();
				}
				return true;
			}
		//	this->S[num].ustawPozycje(wiersz, kolumna);
		}
		else {
			return false;
		}
	}
	else return false;
}

bool plansza::ustawStatekLosowo()
{
	static bool pierwszeLosowanie = true;
	if (pierwszeLosowanie)
	{
		srand(time(NULL));
		pierwszeLosowanie = false;
	}
	int wiersz = rand() % 10;
	int kolumna = rand() % 10;
	for (int num = 0; num <= 10; num++) {
		while (!(sprawdzOkolice(wiersz, kolumna, num))) {
			wiersz = rand() % 10;
			kolumna = rand() % 10;
		}
		this->ustawStatek(wiersz, kolumna, num);
	}
	if (this->czyWszystkieUstawione()) {
		return true;
	}
	else return false;
}

bool plansza::sprawdzOkolice(int wiersz, int kolumna, int num)
{
	if (this->S[num].czyPoziomy()) {
		for (int i = -1; i < 2; i++) {//od -1 bo musi sprawdzic pole u gory, pole ktore jest wybrane i pole u dolu
			for (int j = -1; j < this->S[num].zwrocRozmiar() + 1; j++) {//analogicznie jak petla wyzej, tylko sprawdza po dlugosci statku czy zadne pole nie jest zajete
				if (czyWgranicach(wiersz, kolumna, i, j)) {					
					if (wiersz + i > 9 || wiersz + i < 0) {
						if (kolumna + this->S[num].zwrocRozmiar() <= 10) {
							this->puste = true;
						}
						else {
							this->puste = false;
						}
					}
					else if (kolumna + j > 9 || kolumna + j < 0) {
						if (kolumna + this->S[num].zwrocRozmiar() <= 10) {
							this->puste = true;
						}
						else {
							this->puste = false;
						}
					}
					else if (!(czyStatek(wiersz + i, kolumna + j))) {
						this->puste = true;
					}
					else {
						this->puste = false;
					}
					if (!(this->puste)) { //jezeli nie jest puste to od razu wyrzuca mozliwosc umieszczenia statku
						return false;
					}

				}
				else {
					//std::cout << "poza granicami";
					return false;
				}
			}
		}
	}
	else {//tak samo jak wyzej tylko jesli statek jest pionowy
		for (int i = -1; i < this->S[num].zwrocRozmiar() + 1; i++) {
			for (int j = -1; j < 2; j++) {
				if (czyWgranicach(wiersz, kolumna, i, j)) {
					if (wiersz + i > 9 || wiersz + i < 0) {
						if (wiersz + this->S[num].zwrocRozmiar() <= 10) {
							this->puste = true;
						}
						else {
							this->puste = false;
						}
					}
					else if (kolumna + j > 9 || kolumna + j < 0) {
						if (wiersz + this->S[num].zwrocRozmiar() <= 10) {
							this->puste = true;
						}
						else {
							this->puste = false;
						}
					}
					else if (!(czyStatek(wiersz + i, kolumna + j))) {//jezeli nie ma statku (bstatek = false) to zaprzeczeczenie czyli wchodzi do srodka
						std::cout << "\nWiersz w petli: " << wiersz + i << "kolumna w petli: " << kolumna + j << "bstatek" << czyStatek(wiersz + i, kolumna + i);
						this->puste = true;
					}
					else {
						this->puste = false;
					}
					if (!(this->puste)) {
						return false;
					}

				}
				else {
					return false;
				}
			}

		}
	}
	return puste; //powinno zwrocic true jesli dojdzie do tego momentu
}

bool plansza::czyWgranicach(int wiersz, int kolumna, int i, int j)
{
	if (wiersz + i > 9 && kolumna + j < 0) {
		return true;
	}
	if (wiersz + i > 9 && kolumna + j > 9) {
		return true;

	}
	if (wiersz + i < 0 && kolumna + j < 0) {
		return true;
	}
	if (wiersz + i < 0 && kolumna + j > 9) {
		return true;
	}
	if (wiersz + i > 9 && kolumna + j >= 0 && kolumna + j <= 9) {
		return true;
	}
	if (wiersz + i < 0 && kolumna + j >= 0 && kolumna + j <= 9) {
		return true;
	}

	if (wiersz + i >= 0 && wiersz + i <= 9 && kolumna + j > 9) {
		return true;
	}
	if (wiersz + i >= 0 && wiersz + i <= 9 && kolumna + j < 0) {
		return true;
	}

	if (wiersz + i >= 0 && wiersz + i <= 9 && kolumna + j >= 0 && kolumna + j <= 9) {
		return true;
	}
	else {
		return false;
	}

}

bool plansza::czyKoniec()
{
	bool koniec = false;
	int l = 0;
	for (int i = 0; i < 10; i++) {
		if (this->S[i].czyZatopiony())
			l++;
	}
	if (l == 10) {
		koniec = true;
	}
	return koniec;
}

bool plansza::czyTrafiony(int wiersz, int kolumna)
{
	return this->P[wiersz][kolumna].czyTrafiony(); //czy trafiony z pole.h

}

bool plansza::czyStatek(int wiersz, int kolumna)
{
	return this->P[wiersz][kolumna].czyStatek();
}

bool plansza::zmienMiejsce(int wiersz, int kolumna, int nWiersz, int nKolumna)
{
	return false;
}

bool plansza::czyWszystkieUstawione()
{
	bool ustawione;
	int u = 0;
	for (int i = 0; i < 10; i++) {
		if (zwrocStatek(i).czyUstawiony()) {
			u++;
		}
		else return false;
	}
	if (u == 10) {
		ustawione = true;
	}
	return ustawione;
}

bool plansza::czyPlanszaUstawiona()
{
	if (czyWszystkieUstawione()) {
		this->planszaUstawiona = true;
	}
	return this->planszaUstawiona;
}


bool plansza::strzal(int wiersz, int kolumna)
{
	this->P[wiersz][kolumna].strzal();
	int n = this->zwrocStatek(wiersz, kolumna);
	int r = this->S[n].zwrocRozmiar();
	if (!(this->S[n].czyZatopiony())) {
		if (S[n].czyPoziomy()) {
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < r + 1; j++) {
					if (czyWgranicach(wiersz, kolumna, i, j)) {
						this->P[wiersz][kolumna].strzal();
						this->S[n].trafiony();
						return this->P[wiersz][kolumna].czyPudlo();
					}
				}
			}
		}
	}
		else {
			for (int i = -1; i < r + 1; i++) {
				for (int j = -1; j < 2; j++) {
					if (czyWgranicach(wiersz, kolumna, i, j)) {
						this->P[wiersz][kolumna].strzal();
						this->S[n].trafiony();
						return this->P[wiersz][kolumna].czyPudlo();
					}
				}
			}
		}
}


void plansza::strzal(pole *)
{
}

pole plansza::zwrocPole(int wiersz, int kolumna)
{
	return this->P[wiersz][kolumna];
}

Statek plansza::zwrocStatek(int num)
{
	return this->S[num];
}

int plansza::zwrocStatek(int wiersz, int kolumna)//zwroci indeks statku z tablicy S[10] ktory jest na tym polu
{
	std::pair <int, int> wk = std::make_pair(wiersz, kolumna);
	for (int i = 0; i <= 10; i++) {
		for(int j = 0; j<this->S[i].zwrocRozmiar();j++)
		if (this->S[i].zwrocPozycje(j) == wk) {
			return i;
		}
		else return -1;
	}
	return -1;
}

sf::Sprite plansza::zwrocSprite(int num)
{
	return S[num].sprite;
}

sf::Sprite plansza::zwrocSpritePola(int i, int j)
{
	return P[i][j].sprite;
}

void plansza::ustawPozycjeSprite(int num, int pozX, int pozY)
{
	this->S[num].sprite.setPosition(pozX, pozY);
}

void plansza::ustawOrientacjeStatku(int num, bool poziom)
{
	this->S[num].ustawOrientacje(poziom);
}

void plansza::drawPlansza(sf::RenderWindow &w, int pozX, int pozY)
{
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {
			if (this->P[i][j].czyStatek()) {
				if (!(this->P[i][j].czyTrafiony())) {
					this->P[i][j].sprite = wszystkieSprites.statek1Sprite;
				}
			}
			this->P[i][j].drawPole(w, pozX, pozY);
		}
	}
}

void plansza::drawPlanszaUkryta(sf::RenderWindow &w, int pozX, int pozY) 
{
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {
			if (this->P[i][j].czyStatek()) {
				if (!(this->P[i][j].czyTrafiony())) {
					this->P[i][j].sprite = wszystkieSprites.poleSprite;
				}
			}
			this->P[i][j].drawPole(w, pozX, pozY);
		}
	}
}

void plansza::drawWybor(sf::RenderWindow & w, int pozX, int pozY)
{
	for (int i = 0; i < 10; i++) {
		this->S[i].drawStatek(w, i * 100, pozY);
	}
}

pole * plansza::poleNad(pole *)
{
	return nullptr;
}

pole * plansza::polePod(pole *)
{
	return nullptr;
}

pole * plansza::poleLewe(pole *)
{
	return nullptr;
}

pole * plansza::polePrawe(pole *)
{
	return nullptr;
}