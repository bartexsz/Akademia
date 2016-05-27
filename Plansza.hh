/*
 * Plansza.hh
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */

#ifndef PLANSZA_HH_
#define PLANSZA_HH_

#include <list>

using namespace std;

enum color{
	white = 0,
	black = 1
};

class Pionek{
private:
	int _x;
	int _y;
	color _c;
public:
	Pionek(color c, int x, int y){
		_c = c;
		_x = x;
		_y = y;
	}
	void SetColor(color c);
	color GetColor();
	void SetX(int x);
	int GetX();
	void SetY(int y);
	int GetY();
};

class Plansza{
private:
	Pionek *tab[8][8];
	list<Plansza> lista;
};

class Tablica
{
private:
	Pionek *tab[8][8];
	list<Pionek> WhiteList;
	list<Pionek> BlackList;
	Plansza drzewo;
public:
	int CheckLeft(Pionek P); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	int CheckRight(Pionek P); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	void MoveLeft(Pionek *P);
	void MoveRight(Pionek *P);
	void BeatLeft(Pionek *P);
	void BeatRight(Pionek *P);
	void Wyswietl();
	void Initiation();
};



#endif /* PLANSZA_HH_ */
