/*
 * MinMax.hh
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */

#ifndef MINMAX_HH_
#define MINMAX_HH_

#include <stack>
#include "Move.hh"

using namespace std;

class Node{
private:
	int x;
	int y;
	int color;
	stack<int[4]>;
};

class MinMax{
private:
	Pole tab[8][8];
	list< list<int[3]> > Graf;
	Move M;
public:
	void CopyTab(Pole main_tab[8][8]);
	int Value(); // funkcja oceniajaca
	void Algorithm(Pole main_tab[8][8]);
	void MinMax();
};





#endif /* MINMAX_HH_ */
