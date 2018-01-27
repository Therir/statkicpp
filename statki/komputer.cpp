#include "stdafx.h"
#include "komputer.h"
#include "plansza.h"


komputer::komputer()
{
	this->strzalX = 0;
	this->strzalY = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->tablicaStrzalow[i][j] = 0;
		}
	}
}


komputer::~komputer()
{
}

void komputer::ustawPlansze(plansza &nowaPlansza)
{
	this->planszaKomputer = nowaPlansza;
}

std::pair<int, int> komputer::strzal()
{
	return std::pair<int, int>();
}

bool komputer::sprawdz(int x, int y)
{
	if (this->planszaKomputer.zwrocPole(x, y).czyTrafiony()) {	// jezeli trafiony to wejdz do srodka
		return false;	//byl juz strzal na to pole, wiec zwroc false
	}
	else return true;//jezeli nie bylo strzalu, to zwroc true
}

int komputer::losujX()
{
	this->wylosowaneX = losuj();
	return this->wylosowaneX;
}

int komputer::losujY()
{
	this->wylosowaneY = losuj();
	return this->wylosowaneY;
}

int komputer::losuj()
{
	static bool pierwszeLosowanie = true;
	if (pierwszeLosowanie)
	{
		srand(time(NULL));
		pierwszeLosowanie = false;
	}
	return rand() % 10;;
}

void komputer::komputerLatwy()
{
	bool strzal = !(this->komputerStrzalRand()); //po zaprzeczeniu - jezeli trafi to true, jezeli nie - false
	while (strzal) {
		strzal = !(this->komputerStrzalRand());//strzela dopoki nie spudluje
	}

}

void komputer::komputerSredni()
{
	int losuj;
	int kierunek;
	bool setPola = false;
	bool strzalLosowy = true;
	bool strzal = false;
	int pierwszyDobryX, pierwszyDobryY, ostatniDobryX, ostatniDobryY, i;
	//przeniesc do komputer sredni strzal?
	//algorytm strzelania v2
	if (strzalLosowy) {
		 strzal = !(this->komputerStrzalRand());
	}
	if (strzal) {
		if (strzalLosowy) {
			pierwszyDobryX = this->strzalX;
			pierwszyDobryY = this->strzalY;
		}
		i = this->planszaKomputer.zwrocStatek(this->strzalX, this->strzalY);
		losuj = rand() % 4;
		//przeniesc do komputerStrzalPoziomo/Pionowo w zaleznosci od podanego parametru
		if (losuj == 0) {
			if (!(this->planszaKomputer.zwrocStatek(i).czyZatopiony())) {
				while (sprawdz(strzalX - 1, strzalY)) {//nie bylo strzelone
					this->strzalX = this->strzalX - 1;
					if (!(this->planszaKomputer.strzal(this->strzalX, this->strzalY))) {//jezeli pudlo to break i sprawdza w dol
						this->strzalX = pierwszyDobryX;
						this->strzalY = pierwszyDobryY;
						break;
					}
					else {//jezeli nie to strzela dalej w gore
						ostatniDobryX = this->strzalX;
						ostatniDobryY = this->strzalY;
					}
				}//jezeli jest poza while i nie jest zatopiony to trzeba sprawdzic w dol
			}
			if (!(this->planszaKomputer.zwrocStatek(i).czyZatopiony())) {//jezeli nie jest zatopiony to wchodzi do petli i tak samo jak wyzej tylko +1
				while (sprawdz(strzalX + 1, strzalY)) {//nie bylo strzelone
					this->strzalX = this->strzalX + 1;
					if (!(this->planszaKomputer.strzal(this->strzalX, this->strzalY))) {//jezeli pudlo to break i sprawdza w dol
						this->strzalX = pierwszyDobryX;
						this->strzalY = pierwszyDobryY;
						break;
					}
					else {//jezeli nie to strzela dalej w gore
						ostatniDobryX = this->strzalX;
						ostatniDobryY = this->strzalY;
					}
				}
			}
		}
		if (losuj == 1) {
			if (!(this->planszaKomputer.zwrocStatek(i).czyZatopiony())) {
				while (sprawdz(strzalX, strzalY - 1)) {//nie bylo strzelone
					this->strzalY = this->strzalY - 1;
					if (!(this->planszaKomputer.strzal(this->strzalX, this->strzalY))) {//jezeli pudlo to break i sprawdza w dol
						this->strzalX = pierwszyDobryX;
						this->strzalY = pierwszyDobryY;
						break;
					}
					else {//jezeli nie to strzela dalej w gore
						ostatniDobryX = this->strzalX;
						ostatniDobryY = this->strzalY;
					}
				}//jezeli jest poza while i nie jest zatopiony to trzeba sprawdzic w dol
			}
			if (!(this->planszaKomputer.zwrocStatek(i).czyZatopiony())) {//jezeli nie jest zatopiony to wchodzi do petli i tak samo jak wyzej tylko +1
				while (sprawdz(strzalX, strzalY + 1)) {//nie bylo strzelone
					this->strzalY = this->strzalY + 1;
					if (!(this->planszaKomputer.strzal(this->strzalX, this->strzalY))) {//jezeli pudlo to break i sprawdza w dol
						this->strzalX = pierwszyDobryX;
						this->strzalY = pierwszyDobryY;
						break;
					}
					else {//jezeli nie to strzela dalej w gore
						ostatniDobryX = this->strzalX;
						ostatniDobryY = this->strzalY;
					}
				}
			}
		}
		if (losuj == 2) {
			if (!(this->planszaKomputer.zwrocStatek(i).czyZatopiony())) {
				while (sprawdz(strzalX + 1, strzalY)) {//nie bylo strzelone
					this->strzalX = this->strzalX + 1;
					if (!(this->planszaKomputer.strzal(this->strzalX, this->strzalY))) {//jezeli pudlo to break i sprawdza w dol
						this->strzalX = pierwszyDobryX;
						this->strzalY = pierwszyDobryY;
						break;
					}
					else {//jezeli nie to strzela dalej w gore
						ostatniDobryX = this->strzalX;
						ostatniDobryY = this->strzalY;
					}
				}//jezeli jest poza while i nie jest zatopiony to trzeba sprawdzic w dol
			}
			if (!(this->planszaKomputer.zwrocStatek(i).czyZatopiony())) {//jezeli nie jest zatopiony to wchodzi do petli i tak samo jak wyzej tylko +1
				while (sprawdz(strzalX - 1, strzalY)) {//nie bylo strzelone
					this->strzalX = this->strzalX - 1;
					if (!(this->planszaKomputer.strzal(this->strzalX, this->strzalY))) {//jezeli pudlo to break i sprawdza w dol
						this->strzalX = pierwszyDobryX;
						this->strzalY = pierwszyDobryY;
						break;
					}
					else {//jezeli nie to strzela dalej w gore
						ostatniDobryX = this->strzalX;
						ostatniDobryY = this->strzalY;
					}
				}
			}
		}
		if (losuj == 3) {
			if (!(this->planszaKomputer.zwrocStatek(i).czyZatopiony())) {
				while (sprawdz(strzalX, strzalY + 1)) {//nie bylo strzelone
					this->strzalY = this->strzalY + 1;
					if (!(this->planszaKomputer.strzal(this->strzalX, this->strzalY))) {//jezeli pudlo to break i sprawdza w dol
						this->strzalX = pierwszyDobryX;
						this->strzalY = pierwszyDobryY;
						break;
					}
					else {//jezeli nie to strzela dalej w gore
						ostatniDobryX = this->strzalX;
						ostatniDobryY = this->strzalY;
					}
				}//jezeli jest poza while i nie jest zatopiony to trzeba sprawdzic w dol
			}
			if (!(this->planszaKomputer.zwrocStatek(i).czyZatopiony())) {//jezeli nie jest zatopiony to wchodzi do petli i tak samo jak wyzej tylko +1
				while (sprawdz(strzalX, strzalY - 1)) {//nie bylo strzelone
					this->strzalY = this->strzalY - 1;
					if (!(this->planszaKomputer.strzal(this->strzalX, this->strzalY))) {//jezeli pudlo to break i sprawdza w dol
						this->strzalX = pierwszyDobryX;
						this->strzalY = pierwszyDobryY;
						break;
					}
					else {//jezeli nie to strzela dalej w gore
						ostatniDobryX = this->strzalX;
						ostatniDobryY = this->strzalY;
					}
				}
			}
			if (this->planszaKomputer.zwrocStatek(i).czyZatopiony()) {
				strzalLosowy = true;
			}
		}
	}
}




void komputer::komputerTrudny()
{
}

void komputer::komputerSredniStrzalX(int x)
{
}

void komputer::komputerSredniStrzalY()
{
}

bool komputer::komputerStrzalRand()//losuje x,y sprawdza czy strzelono juz tam, jak nie to strzela, zwraca zmienna pudlo z klasy pole, true - jesli pudlo, false - jesli trafienie
{
	int tmpX, tmpY;
	tmpX = this->losujX();//pierwsze przypisanie
	tmpY = this->losujY();
	while (!(this->sprawdz(tmpX, tmpY))) {//petla do wylosowania nowych wspolrzednych, jesli poprzednie byly juz wykorzystane
		tmpX = this->losujX();
		tmpY = this->losujY();
	}
	this->strzalX = tmpX;
	this->strzalY = tmpY;

	return this->planszaKomputer.strzal(strzalX, strzalY);//tutaj mozna bezposrednio na planszy, bo nie trzeba sprawdzac czy x,y miesci sie w zakresie tablicy, tak jak w przypadku klikniecia
														 //zwroci true jesli pudlo, false jesli trafienie
}

