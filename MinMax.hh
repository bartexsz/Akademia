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
#include "Move.hh"

using namespace std;


class MinMax{
private:
	Pole tab[8][8];
	int main_depth;
	list<Possibility> move;
	list<Possibility> tmp_move;
	int value;
	int x,y,tmp_x,tmp_y;
	Move M;
public:
	void CopyTab(Pole main_tab[8][8]);
	int Value(); // funkcja oceniajaca
	int MinMaxRecursion(int depth, Pole player);
	void Algorithm(Pole main_tab[8][8], int depth, list<Possibility> &Lista, int &xx, int &yy);
	void CopyMove();
};





#endif /* MINMAX_HH_ */
