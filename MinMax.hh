/*
 * MinMax.hh
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */

#ifndef MINMAX_HH_
#define MINMAX_HH_

#include <list>
#include "Move.hh"

using namespace std;


class MinMax{
private:
	Pole tab[8][8];
	list< list<int[2]> > Graf;
	Move M;
public:
	void CopyTab(Pole main_tab[8][8]);
	int Value(int x, int y); // funkcja oceniajaca
	void MakeTree(Pole main_tab[8][8]);
};





#endif /* MINMAX_HH_ */
