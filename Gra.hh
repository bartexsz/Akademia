/*
 * Gra.hh
 *
 *  Created on: May 28, 2016
 *      Author: damian
 */

#ifndef GRA_HH_
#define GRA_HH_

#include <iostream>
#include "Move.hh"
#include <list>
#include "MinMax.hh"

using namespace std;

class Gra{
private:
	Pole tab[8][8];
	int pionki_biale;
	int pionki_czarne;
	MinMax minmax;
public:
	void Initiation();
	void Wyswietl(Pole gracz);
	void Player_vs_Player();
	bool CzyKoniec();
	void TestDamian();
	void Player_vs_Ameba();
	void Test();
	void Interfejs_Gracza(Pole tab,int &x,int &y, list<Possibility> &possibilities, Pole gracz);
	void Wybor(int &x, int &y, Pole gracz);
	void Odejmij_pionka(Pole pionek);
	Possibility CoKcesz(int wybor);
	bool CzyMozna(list<Possibility> &cobylo, Possibility wybor);
};


#endif /* GRA_HH_ */
