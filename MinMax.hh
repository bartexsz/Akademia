/*
 * MinMax.hh
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */

#ifndef MINMAX_HH_
#define MINMAX_HH_

#define DEPTH 1


#include <list>
#include <climits>
#include <iostream>
#include "Move.hh"

using namespace std;


class MinMax{
private:
	int licznik = 0;
	Pole tab[8][8];
	int main_depth;
	list<Possibility> move;
	list<Possibility> tmp_move;
	int value;
	int x,y,tmp_x,tmp_y;
	Move M;
	int pionki_biale;
	int pionki_czarne;
public:
	void CopyTab(Pole main_tab[8][8]);
	int Value(); // funkcja oceniajaca
	int MinMaxRecursion(int depth, Pole player);
	int Algorithm(Pole main_tab[8][8], int depth, list<Possibility> &Lista, int &xx, int &yy);
	void MultipleMove(int depth, Pole player,int x, int y, int &best_value);
	void CopyMove();
	void Wyswietl(Pole gracz);
	int LiczPionki();

};





#endif /* MINMAX_HH_ */
