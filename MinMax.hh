/*
 * MinMax.hh
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */

#ifndef MINMAX_HH_
#define MINMAX_HH_

#include <list>
#include "Plansza.hh"

using namespace std;


class MinMax{
private:
	Plansza first;
	Move M;
public:
	void CopyTab(Pionek *tab[8][8], Pionek *target[8][8]);
	void MakeTree(Tablica tab);
};





#endif /* MINMAX_HH_ */
