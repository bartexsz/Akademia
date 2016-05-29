/*
 * Plansza.hh
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */

#ifndef PLANSZA_HH_
#define PLANSZA_HH_

#include <iostream>
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
	int _wartosc;
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
	void SetWartosc(int w);
	int GetWartosc();
};

class Plansza{
public:
	Pionek *tab[8][8];
	int krawedz;
	list<Plansza> lista;
};

class Move{
public:
	int CheckLeft(Pionek *tab[8][8], Pionek P); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	int CheckRight(Pionek *tab[8][8], Pionek P); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	void MoveLeft(Pionek *tab[8][8], Pionek *P);
	void MoveRight(Pionek *tab[8][8], Pionek *P);
	void BeatLeft(Pionek *tab[8][8], Pionek *P);
	void BeatRight(Pionek *tab[8][8], Pionek *P);
	int GetWartosc(Pionek P); // funkcja oceniajaca
};



class Tablica
{
friend class MinMax;
private:
	Pionek *tab[8][8];
	list<Pionek> WhiteList;
	list<Pionek> BlackList;
public:
	int CheckLeft(Pionek P); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	int CheckRight(Pionek P); // 0 - nie ma ruchu, 1 - normalny ruch, 2 - bicie
	void MoveLeft(Pionek *P);
	void MoveRight(Pionek *P);
	void BeatLeft(Pionek *P);
	void BeatRight(Pionek *P);
	void SetWartosc(Pionek *P); // funkcja oceniajaca
	void Wyswietl();
	void Initiation();
};


#endif /* PLANSZA_HH_ */
