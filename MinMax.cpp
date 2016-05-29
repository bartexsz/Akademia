/*
 * MinMax.cpp
 *
 *  Created on: May 27, 2016
 *      Author: damian
 */

#include "MinMax.hh"

void MinMax::MakeTree(Tablica tab){
	CopyTab(tab.tab,first.tab);
	for(list<Pionek>::iterator it = tab.BlackList.begin(); it != tab.BlackList.end(); it++){
		Move.GetValue()
	}
}

void MinMax::CopyTab(Pionek *tab[8][8], Pionek *target[8][8]){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++)
			target[i][j] = tab[i][j];
	}
}
