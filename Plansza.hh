/*
 * Plansza.hh
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */

#ifndef PLANSZA_HH_
#define PLANSZA_HH_
#include <iostream>
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

class Tablica
{
	enum pionek{pusty=0, bialy=1, czarny=2};
	pionek tab[8][8];
public:
	void Wyswietl();
};

#endif /* PLANSZA_HH_ */